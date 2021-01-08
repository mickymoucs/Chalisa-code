/*โปรแกรมคำนวณและแสดงผลโหวตที่มากที่สุดจะเป็นผู้ชนะ*/

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

     int voter_count=0;int i=0;int j=0;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
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
    for ( i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for ( i = 0; i < voter_count; i++)
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

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
       for ( i = 0; i < candidate_count; i++)
    {
    if (strcmp(candidates[i].name, name) == 0)
        {
            int a = candidates[i].votes++;
            return true;
        }
    }
    return false;
}


// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max = 0;
    for ( i = 0; i < candidate_count; i++)
    {
        if (max < candidates[i].votes)
            max = candidates[i].votes;
    }
    if (max == 0)
        return;
    for (i = 0; i < candidate_count; i++)
    {
        if (max == candidates[i].votes)
            printf("%s\n", candidates[i].name);
    }
    return;
}