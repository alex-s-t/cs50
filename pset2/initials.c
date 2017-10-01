#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *name = get_string();
    
    // checks first char and prints if not a space
    if (name[0] != ' ') {
        printf("%c", toupper(name[0]));
    }
    
    // iterate through all characters in 'name'
    for(int i = 0; i < strlen(name); i++)
    {
        // prints char that immediately follows a space, but that is not a space itself
        if (name[i - 1] == ' ' && name[i] != ' ') {
            printf("%c", toupper(name[i]));
        }
    }

    printf("\n");
}