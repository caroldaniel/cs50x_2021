#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes
int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    //Get input from user
    string input = get_string("Text: ");

    //Count number of letters
    //printf("%i letters\n", count_letters(input));
    
    //Count number of words
    //printf("%i words\n", count_words(input));
    
    //Count number of sentences
    //printf("%i sentences\n", count_sentences(input));
    
    //Find the avarage number of letters per 100 words
    float l = 100.0 * count_letters(input) / count_words(input);
    //printf("L: %f\n", l);
    
    //Find the avarage number of sentences per 100 words
    float s = 100.0 * count_sentences(input) / count_words(input);
    //printf("s: %f\n", s);
    
    //Find the Coleman-Liau index
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    //printf("index: %f\n", index);
    
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

//Make function to count number of letters
int count_letters(string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            sum = sum + 1;
        }

        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            sum = sum + 1;
        }

        else
        {
            sum = sum + 0;
        }
    }
    return sum;
}

//Make function to count the number of words

int count_words(string text)
{
    int sum = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            sum = sum + 1;
        }
        else
        {
            sum = sum + 0;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (text[i + 1] == 32)
            {
                sum = sum + 1;
            }
            else 
            {
                sum = sum + 0;
            }
        }
        else
        {
            sum = sum + 0;
        }
    }
    return sum;
}
