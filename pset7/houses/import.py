import cs50
import csv
import os
from sys import argv, exit

if not (len(argv) == 2 and os.path.isfile(argv[1]) and ".csv" in argv[1]):
    print("Usage: python import.py filename")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

with open(argv[1], "r") as file:

    reader = csv.DictReader(file)

    for row in reader:
        name = row["name"].split(' ')

        if len(name) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], name[1], name[2], row["house"], row["birth"])
        elif len(name) == 2:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], None, name[1], row["house"], row["birth"])
        else:
            print("Unacceptbale name detected")
            exit(2)

    exit(0)