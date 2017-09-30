#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    
    // wait until appropriate height is entered
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    
    // iterate for each line starting 1
    for (int i = 1; i <= height; i++)
    {
        // draw spaces
        for (int j = 1; j <= height - i; j++) 
        {
            printf(" ");
        }
        
        // draw hashes
        for (int j = 1; j <= i; j++) 
        {
            printf("#"); 
        }
        // draw space between both sides of the 'pyramid'    
        printf("  ");
        
        // draw second side of pyramid (just hashes, and then new line char)
        for (int j = 1; j <= i; j++)
        {
            printf("#"); 
        }
        
        printf("\n");
    }
}
