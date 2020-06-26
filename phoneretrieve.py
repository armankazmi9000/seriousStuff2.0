#importing list function
import csv

#main function
def main():
   
    with open("phonebook.csv", "r") as file:
        reader = csv.DictReader(file)
        print ("\n", end ="")
        name = input("name: ")
        for row in reader:
            
            if name.lower() == row["name: "]:
                print ("\n", end ="")
                print ("Number: ", end = "")
                print (row["number: "])
                print ("Age: ", end = "")
                print (row["age: "])
                print ("Address: ", end = "")
                print (row["address:"])
                print ("\n", end ="")
                return True
                    
        print ("\n", end ="")
        print("not found! run python phone.py to add contact!")
main()