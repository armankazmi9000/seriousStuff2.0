#importing list function
import csv

#getting input from user to store into database
name = input("name: ")
number = input("number: ")
age = int(input("age: "))
address = input("address: ")

#opening the file(database), writing the users input information, closing the file
with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow((name, number, age, address))

