#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt user about credit card number
    long number = get_long("Number: ");

    //Separate digits in credit card prompted

    //Find dividers 
    long divider[16];
    for (int i = 0; i < 16; i++)
    {
        divider[i] = (long) pow(10, (15 - i));
    }

    long numbers[16];
    for (int i = 0; i < 16; i++)
    {
        numbers[i] = number / divider[i];
        number = number % divider[i];
    }

    // Multiply digits
    int mnumber[16];
    for (int i = 0; i < 16; i++)
    {
        mnumber[i] = numbers[i] * 2;
    }

    // Separate digits from the doubles
    // Find tens from decimal
    int mnumberd [16];
    for (int i = 0; i < 16; i++)
    {
        mnumberd[i] = mnumber[i] / 10;
    }
    // Find unit from decimal
    int mnumberr [16];
    for (int i = 0; i < 16; i++)
    {
        mnumberr[i] = mnumber[i] % 10;
    }

    //Sum of tens of every other digit
    int sumtens = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        sumtens = sumtens + mnumberd[i];
    }

    //Sum of units of every other digit
    int sumunits = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        sumunits = sumunits + mnumberr[i];
    }

    //Sum of every other digit
    int sumdigit = 0;
    for (int i = 1; i < 16; i = i + 2)
    {
        sumdigit = sumdigit + numbers[i];
    }

    //Sum total of valid digits
    int sumtotal = sumtens + sumunits + sumdigit;

    //Check last digit of total
    int digit[3];
    for (int i = 0; i < 3; i++)
    {
        digit[i] = sumtotal / (int) pow(10, 2 - i);
        sumtotal = sumtotal % (int) pow(10, 2 - i);
    }

    //Check if credit card is valid
    if (digit[2] != 0)
    {
        printf("INVALID\n");
    }

    //Check if card is AMEX
    else if (numbers[0] == 0 && numbers[1] == 3)
    {
        if (numbers[2] == 4 || numbers[2] == 7)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //Check if card is MasterCard
    else if (numbers[0] == 5)
    {
        if (numbers[1] == 1 || numbers[1] == 2 || numbers[1] == 3 || numbers[1] == 4 || numbers[1] == 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    //Check if card is Visa
    else if (numbers[0] == 4)
    {
        printf("VISA\n");
    }
    else if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 4)
    {
        printf("VISA\n");
    }

    //Everything else is invalid
    else
    {
        printf("INVALID\n");
    }
}