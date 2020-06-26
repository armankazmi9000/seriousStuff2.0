//program stores information and prints info when called by the name of person in array people
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
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
    
    FILE *file = fopen("phone.csv", "a");
    if (!file)
    {
        return 1;
    }
    
        //itereates a linear search alogrithm loop to go through all strings of the people array
        for (int j = 0; j <= 5; j++)
        {
            //function to print the info once there is a match of the who input and the people.name array
            if (strcmp(name, who) == 0)
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


