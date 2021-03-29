#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Number: ");

    if (n <= 0)
    {
        printf("collatz usage: only positive integer\n");
        return 1;
    }

    else
    {
        printf("Collatz is %i\n", collatz(n));
        return 0;
    }
}

int collatz(int n)
{
    //base case
    if ( n == 1)
    {
        return 0;
    }

    //if n is even
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n / 2);
    }

    //if n is odd number
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}
