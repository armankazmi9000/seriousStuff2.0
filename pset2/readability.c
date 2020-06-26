//program that calculates the reading level of any given text
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//main function
int main(void)
{
    //gets users' input of what text they want to analyze
    char *text = get_string("Text: ");
    
    //variables for equation
    float letters = 0, words = 1, sentences = 0;
    
    //iterates a linear search algorithm loop to anaylze all characters of the array(string)
    for (int i = 0, n = strlen(text); i < n; i++)
    {   
        //searches for any letter of the alphabet, if so, add 1 value of letter
        if (isalpha(text[i]))
        {
            letters++;
        }
        //searches for any spaces, if so, add 1 value of space
        else if (isspace(text[i]))
        {
            words++;
        }
        //searches for any punctuation marks, if so, add 1 value of sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        
        
    }
    
    //calculations necesary for the equation to get grade level
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = ((0.0588 * L) - (0.296 * S) - 15.8);
        
    //conditionals to print the approximate reading grade level
    if (index >= 1 && index <= 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
