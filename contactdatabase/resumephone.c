//program stores information and prints info when called by the name of person in array people
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//structure to store different elements into a variable
typedef struct
{
    char * name;
    char * number;
    char * age;
}
person;

//main function
int main(void)
{
    //initialized an array
    person people[100];
    
    //this is where all info is stored, based on people array and specific element of person structure
    people[0].name = "ali";
    people[0].number = "916-316-8650";
    people[0].age = "21";
    
    people[1].name = "tara";
    people[1].number = "916-316-8649";
    people[1].age = "55";
    
    people[2].name = "mohsin";
    people[2].number = "916-396-9225";
    people[2].age = "58";
    
    people[3].name = "home";
    people[3].number = "916-791-9117";
    people[3].age = "none";
    
    people[4].name = "arman";
    people[4].number = "916-792-1819";
    people[4].age = "15";
    
    people[5].name = "bob";
    people[5].number = "911";
    people[5].age = "123456789";
    
    //loops input if given name that does not match
    while (true)
    {
        //user input to get the string of the person they are looking for
        printf("    ");
        printf("\n");
        char * who = get_string("Who are you looking for: ");
        
        //iterates a loop until all characters of the strings have been analyzed
    for (int i = 0, n = strlen(who); i <= n; i++)
        {
            //function to convert all uppercase letters to lowercase, leave lower as lower
            if(isupper(who[i]))
            {
                who[i] = who[i] + 32;
            }
        }    
    
        //itereates a linear search alogrithm loop to go through all strings of the people array
        for (int j = 0; j <= 5; j++)
        {
            //function to print the info once there is a match of the who input and the people.name array
            if (strcmp(people[j].name, who) == 0)
            {
                printf("\n");
                printf("Number: %s\n", people[j].number);
                printf("Age: %s\n", people[j].age);
                printf("\n");
                return 0;

            }
        }   
    }
        //function to tell user what to do in case of error
        printf("\n");
        printf("Click the up arrow then enter to try again! :) \n");
        printf("\n");
        return 1;
}


