from cs50 import SQL
from csv import reader
from sys import argv


if len(argv) < 2:
    print("error")
    exit()

db = SQL("sqlite:///students.db")
students = db.execute("Select first, middle, last, birth from students where house = (?) order by last, first;", argv[1])

for student in students:
    if not student["middle"] == 'None':
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")
