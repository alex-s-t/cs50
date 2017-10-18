#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_CHAR 0 /* first char in input string */
#define SUCCESS 0      /* return value for success */

/* prints out the initials of a name
** e.g. alex apple -> AA */
int main(void)
{
    char *name = get_string();
    int i = 0;

    int name_length = strlen(name);

    /* checks first char and prints if not a space */
    if (name[INITIAL_CHAR] != ' ') {
        printf("%c", toupper(name[INITIAL_CHAR]));
    }

    /* iterate through all characters in 'name' */
    for(i = 1; i < name_length; i++) {

        /* prints char that immediately follows a space,
        ** but that is not a space itself */
        if (name[i - 1] == ' ' && name[i] != ' ') {
            printf("%c", toupper(name[i]));
        }
    }

    printf("\n");

    return SUCCESS;
}