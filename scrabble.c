#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (compute_score(word1) > compute_score(word2))
    {
        printf("Player 1 wins!\n");
    }

    if (compute_score(word1) < compute_score(word2))
    {
        printf("Player 2 wins!\n");
    }

    if (compute_score(word1) == compute_score(word2))
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //Check if char's lower case
        int SCORE[n];
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            SCORE[i] = POINTS[(int) word[i] - 97];

        }

        //Check if char's upper case
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            SCORE[i] = POINTS[(int) word[i] - 65];
        }

        //Check if char is not a letter
        else
        {
            SCORE[i] = 0;
        }
        sum = sum + SCORE[i];
    }
    return sum;
}
