select name.people, title.movies from movies
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.movie_id