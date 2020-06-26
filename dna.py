#importing list function
import csv

#main function
def main():
   
    with open("large.csv", "r") as file:
        reader = csv.DictReader(file)
        
        print ("\n", end ="")
        name = input("who: ")

        for row in reader:
            if name == row["name"]:
                print (row["AGATC"],row["TTTTTTCT"],row["AATG"])
                return True
                    
        
main()