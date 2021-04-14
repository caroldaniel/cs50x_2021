#include <cs50.h>
#include <stdio.h>

/* 
**  Description 
**  -----------
**  Prints a pyramide similar to the one found on the Mario's game's graphics.   
**  Height of pyramide is defined by the user.
**
**  Returns
**  -------
**  A graphical representation of the pyramide of the selected height. 
*/

int main(void)
{
    // Get positive interger from user
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print piramide with height defined by user
    int line;
    for (line = 0; line < height; line++)
    {
        int block = line + 1;
        int space;

        //Print blank spaces according to line specs
        for (space = height - block; space > 0 ; space--)
        {
            printf(" ");
        }

        //Print block spaces according to line specs
        for (block = line + 1; block > 0 ; block--)
        {
            printf("#");
        }

        //Print black space in middle
        printf("  ");

        // Print rest of the block spaces according to line specs
        for (block = line + 1; block > 0; block--)
        {
            printf("#");
        }
        printf("\n");
    }
}
