/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// declare GLOBAL variable of wordcount !
int count = 0;
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    
    node *trav = root;
    if (trav == NULL) {
        printf("root node could not be accessed");
        return 7;
    }
    
    int index;
    
    for (int i = 0; i < strlen(word) + 1; i++) {
        if (isalpha(word[i])) {
            index = tolower(word[i]) - 97; 
        }
        else {
            index = 26;
        }

        if (trav->children[index] != NULL && i == strlen(word) - 1) {
            trav = trav->children[index];
            if (trav->isWord) {
                return true;
            }
        }
        else if (trav->children[index] == NULL) 
        {
            return false;
        }
        else if (trav->children[index] != NULL) 
        {
            trav = trav->children[index];
        }
        
        
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL) 
    {
        return false;
    }
    root = calloc(1, sizeof(node));
    int node_size = sizeof(node);
    int index;
    
    char word[46] = { '\0' };

    // (for word in dictionary) [load it!]
    while (fscanf(inptr, "%s", word) != EOF) 
    {
        
        count++;
    
        node *trav = root;
        int length = strlen(word);
        // for char in word
        for (int i = 0; i < length; i++) 
        {
            if ((word[i]) != '\'') 
            {
                index = tolower(word[i]) - 97;
            }
            else
            {
                index = 26;
            }
            
            // trav->children: get member 'children' from struct that trav points to
            if (i == length - 1) 
            {
                node *temp = calloc(1, node_size);
                trav->children[index] = temp;
                trav = trav->children[index];
                trav->isWord = true;
            }
            
            else if (trav->children[index] == NULL)
            {
                node *temp = calloc(1, node_size);
                trav->children[index] = temp;
                trav = trav->children[index];
                
            }
            else if (trav->children[index] != NULL)
            {
                trav = trav->children[index];
            }
        }
    }
    
    fclose(inptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    trie_clear(root);
    return true;
}

/**
 * recursive trie unloader
 */
void trie_clear(node * root)
{
    int i;
    
    for (i = 0; i < 27; i++)
    {
        if (root->children[i] != NULL)
        {
            trie_clear(root->children[i]);
        }
    }
    
    free(root);
}