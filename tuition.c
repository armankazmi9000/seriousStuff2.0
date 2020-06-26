#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int cost = get_int("How much does it cost per year in dollars: ");
    int years = get_int("How many years will you be in college: ");
    int inflation = get_int("How much is inflation in percent: ");
   
    int pricetotal = (cost * ((1 + (inflation/100)) ^ (years)));
    
    printf("Total cost after %i years: %i\n", years, price);
}