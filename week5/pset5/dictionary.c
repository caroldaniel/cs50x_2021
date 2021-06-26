// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Initialize int for dictionary size
unsigned int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Make a lowercase version of the word in order to compare with the dictionary version
    char low_word[LENGTH + 1];
    for (int i = 0, n = strlen(word) + 1; i < n; i++)
    {
        if (isupper(word[i]))
        {
            low_word[i] = tolower(word[i]);
        }
        else
        {
            low_word[i] = word[i];
        }
    }

    // Hash word using hash function
    int hash_nbr = hash(low_word);

    // Acess linked list at the hash nbr index
    node *n = table[hash_nbr];

    // Traverse linked list, looking for exact match, using strcasecmp
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }

    // If word is not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // This function must take a word and give back a number
    // Start at the prime number 5381
    unsigned long hash_nbr = 5381;
    int c;

    // Iterate through each letter
    while ((c = *word++))
    {
        // Bitwise left shift 5, add hash, add c
        hash_nbr = ((hash_nbr << 5) + hash_nbr) + c;
    }

    // Make sure the hash is within the array's length
    return hash_nbr % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *ptr_dictionary = fopen(dictionary, "r");

    // Check if NULL
    if (dictionary == NULL)
    {
        return false;
    }

    // Initialize word array
    char ptr_word[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(ptr_dictionary, "%s", ptr_word) != EOF)
    {
        // Create new node for each word found
        node *n = malloc(sizeof(node));

        // Check if null node
        if (n == NULL)
        {
            return false;
        }

        // Copy word found into new node using strcpy
        strcpy(n->word, ptr_word);

        // Hash word to find position in table array
        int hash_nbr = hash(n->word);

        // Put new node in position
        n->next = table[hash_nbr];
        table[hash_nbr] = n;
        dict_size++;
    }

    // Close file pointer
    fclose(ptr_dictionary);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate of hash table to free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign cursor at first node
        node *n = table[i];

        // Iterate in every node of linked list to free them
        while (n != NULL)
        {
            // Make temp equal cursor
            node *tmp = n;
            // Point cursor to next element
            n = n->next;
            // Free tmp
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
