#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Prompt user for name
    string name = get_string("What's your name? ");
// Greet user by name prompted
    printf("Hello, %s!\n", name);
}