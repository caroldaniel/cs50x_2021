#include <cs50.h>
#include <stdio.h>
  
/* 
**  Description 
**  -----------
**  Calculates the number of years it takes for a given population to grow a given amount.  
**  The start and end sizes are given by the user. 
**  The population grows by 1/3 a year given its births, and shrinks 1/4 in the same period. 
**
**  Returns
**  -------
**  Prints the number of years taken to grow.
*/


int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (start > end);

    // Calculate number of years until we reach threshold
    int births = start / 3;
    int deaths = start / 4;
    int population = start;
    int years = 0;

    while (population < end)
    {
        population = population + births - deaths;
        births = population / 3;
        deaths = population / 4;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
