// Saves names and numbers to a CSV file

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open CSV file
    FILE *file = fopen("phone.csv", "a");
    if (!file)
    {
        return 1;
    }

    // Get name and number and age
    string name = get_string("Name: ");
    string number = get_string("Number: ");
    string age = get_string("Age: ");

    // Print to file
    fprintf(file, "%s,%s,%s\n", name, number, age);

    // Close file
    fclose(file);
}
