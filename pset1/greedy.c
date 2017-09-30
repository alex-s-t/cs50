#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;
    int coins; int a; int b;

    do 
    {
        printf("O hai! How much change is owed?\n");
        money = get_float();
    }
    while (money < 0);
    
    // round to account for floating point imprecision
    b = roundf(money * 100);

    coins = b / 25, a = b % 25;
    b = a;
    
    coins += (b / 10), a = b % 10;
    b = a;
    
    coins += (b / 5), a = b % 5;

    coins += a;

    printf("%i\n", coins);
}
