#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Make sure the code has only 2 arguments
    if (argc != 2)
    {
        //Output the error message
        printf("Usage: ./substitution key\n");
        return (1);
    }
    else
    {
        //Name the first argument 'key' and find its length
        string key = argv[1];
        int n = strlen(key);
        
        if (n != 26)
        {
            //Output the error message
            printf("Key must contain 26 characters.\n");
            return (1);
        }
        
        //Make sure key there are no two same letters
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (tolower(key[i]) == tolower(key[j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return (1);
                }

        //Make sure key is prompted using only letters
        for (int i = 0; i < n; i++)
            if (!(islower(key[i]) || isupper(key[i])))
            {
                printf("Key must only contain letters.\n");
                return (1);
            }

        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        n = strlen(plaintext);
        
        for (int i = 0; i < n; i++)
        {
            //If it is prompted a lowercase character, keep lower
            if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                ciphertext[i] = tolower(key[(int) plaintext[i] - 97]);
            }
            //If it is prompted an uppercase character, keep upper
            else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                ciphertext[i] = toupper(key[(int) plaintext[i] - 65]);
            }
            //If what's prompted is not a letter, keep it
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        //Output the ciphered word
        printf("ciphertext: %s\n", ciphertext);
        return (0);
    }
}
