#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cents;
    do
    {
        cents = get_float("how much change? ");//prompts how much change u have//
    }
    while (cents < 0);
    
    int n = cents * 100;//converts change to 100x//
    
    n = round(n);

    
    int c = 0;
    while (n >= 0) //series of steps to go trhough algortihm until it hits zero//
    {
        if (n >= 25)
        {
            n = n - 25;
            c++;
        }
        else if (n >= 10)
        {
            n = n - 10;
            c++;
        }
        else if (n >= 5)
        {
            n = n - 5;
            c++;
        }
        else
        {
            n = n - 1;
            c++;
            
        }
    
    }
    printf("%i\n", c - 1); //prints teh number of coins needed//

    
    
}