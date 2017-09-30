#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // converts standard minute of water use in a shower to bottles of water (12oz bottles)
    printf("Minutes: ");
    
    int minutes = get_int();
    
    printf("Bottles: %i\n", minutes * 12);
}