#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for infdgdf age
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate dfgfdgdfgdates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter = get_int("Number of voters: ");

    // Loop ofdsvfvf
    for (int i = 0; i < voter; i++)
    {
        string name = get_string("Vote: ");

        // Check for ifgdg
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display sadaa
    print_winner();
}

// Update vote tosadadasdasdasd tals given a asd vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // TODOsdsad end
    return false;
}

// Print theasdsadasd
void print_winner(void)
{
    // TODO
    int maxvotes = 0;
    // find hiyeyee
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates[i].votes;
        }
    }
    // yeeeete
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    // yeeet
    return;
}
