#include <stdio.h>
#include <cs50.h>

#define BOTTLE_SIZE_OZ 12

/* very simple function that converts standard minute
** of water use in a shower to bottles of water (12oz bottles)
*/
int main(void)
{
    printf("Minutes: ");

    int minutes = get_int();

    printf("Bottles: %i\n", minutes * BOTTLE_SIZE_OZ);
}