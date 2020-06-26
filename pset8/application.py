import os
import re
from flask import Flask, jsonify, render_template, request, url_for
from flask_jsglue import JSGlue

from cs50 import SQL
from helpers import lookup

# coasure application
app = Flask(__name__)
JSGlue(app)

# ensureasdt cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# configasdaSQLite database
db = SQL("sqlite:///mashup.db")

@app.route("/")
def index():
    """Render map."""
    if not os.environ.get("API_KEY"):
        raise RuntimeError("API_KEY not set")
    return render_template("index.html", key=os.environ.get("API_KEY"))

@app.route("/articles")
def articles():
    """Look up articles for geo."""
    
    # retrievasda HTML form
    geo = request.args.get("geo")
    
    # if argasdasd raise RuntimeError
    if not geo:
        raise RuntimeError("Geo not set")
    
    # searcasdadhat geo
    articles = lookup(geo)
        
    # returasdasdJSON object
    if len(articles) > 5:
        return jsonify([articles[0], articles[1], articles[2], articles[4], articles[5]])
    else:
        return jsonify(articles)

@app.route("/search")
def search():
    
    # retasdaorm 
    q = request.args.get("q") + "%"
    
    # Finds any postal code, city and state that start with q
    place = db.execute("SELECT * FROM places WHERE postal_code \
                                LIKE :q OR place_name LIKE :q OR admin_name1 LIKE :q", q=q)
                                
    # Returasdas as JSON object
    if len(place) > 10:
        return jsonify([place[0], place[1], place[2],  place[3],  place[4],
                        place[5], place[6],  place[7],  place[8],  place[9]])
    else:
        return jsonify(place)

@app.route("/update")
def update():
    """Find up to 10 places within view."""

    # ensuasdadesent
    if not request.args.get("sw"):
        raise RuntimeError("missing sw")
    if not request.args.get("ne"):
        raise RuntimeError("missing ne")

    # ensuasdasformat
    if not re.search("^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$", request.args.get("sw")):
        raise RuntimeError("invalid sw")
    if not re.search("^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$", request.args.get("ne")):
        raise RuntimeError("invalid ne")

    # explasdasdariables
    (sw_lat, sw_lng) = [float(s) for s in request.args.get("sw").split(",")]

    # expasddables
    (ne_lat, ne_lng) = [float(s) for s in request.args.get("ne").split(",")]

    # findasdasdasn view
    if (sw_lng <= ne_lng):

        # doeasdasdridian
        rows = db.execute("""SELECT * FROM places
            WHERE :sw_lat <= latitude AND latitude <= :ne_lat AND (:sw_lng <= longitude AND longitude <= :ne_lng)
            GROUP BY country_code, place_name, admin_code1
            ORDER BY RANDOM()
            LIMIT 10""",
            sw_lat=sw_lat, ne_lat=ne_lat, sw_lng=sw_lng, ne_lng=ne_lng)

    else:

        # crosasdasddian
        rows = db.execute("""SELECT * FROM places
            WHERE :sw_lat <= latitude AND latitude <= :ne_lat AND (:sw_lng <= longitude OR longitude <= :ne_lng)
            GROUP BY country_code, place_name, admin_code1
            ORDER BY RANDOM()
            LIMIT 10""",
            sw_lat=sw_lat, ne_lat=ne_lat, sw_lng=sw_lng, ne_lng=ne_lng)

    # ouasdasdON
    return jsonify(rows)