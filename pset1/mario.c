#include <cs50.h>
#include <stdio.h>

#define SUCCESS 0 /* return value for success */

/* prints out a mario 'pyramid' as at the end of levels */
int main(void)
{
    int height = 0;

    int i = 0;
    int j = 0;

    /* wait until appropriate height is entered */
    do {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    /* iterate for each line starting 1 */
    for (i = 1; i <= height; i++) {

        /* draw spaces */
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }

        /* draw hashes */
        for (j = 1; j <= i; j++) {
            printf("#");
        }

        /* draw space between both sides of the 'pyramid' */
        printf("  ");

        /* draw second side of pyramid */
        for (j = 1; j <= i; j++) {
            printf("#");
        }

        printf("\n");
    }

    return SUCCESS;
}
