#include <cs50.h>
#include <stdio.h>

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

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
