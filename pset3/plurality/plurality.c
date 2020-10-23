#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Define a new structure called candidate, with name and int vote
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of all possible candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes (vote and print winner)
bool vote(string name);

void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) // Populating array of candidates with information
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0; // All candidates start with 0 votes
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Define function to get location of candidate name in array based on vote
int get_index(string name)
{
    for (int i = 0; i < candidate_count; i++)
        if (strcmp(candidates[i].name, name) == 0)
        {
            return i;
        }

    return -1;
}

// Update vote totals given a new vote
bool vote(string name)
{

    int index = get_index(name);
    if (index != -1)
    {
        candidates[index].votes += 1;
        return true;
    }
    return false;
}

// Define get_max function, to define max votes received by a candidate
int get_max(void)
{
    int max_votes = candidates[0].votes;
    // Iterate through all candidates to tally who has more votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    return max_votes;
}
// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = get_max();
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes == max_votes)
            {
                printf("%s\n", candidates[i].name);
            }
        }
    }
}
