#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    do {
    int q = 0;
    int z = 0;
    printf("Number: ");
    long long card_number = get_long_long();

    /* of course this is uneccesary, but I did it in week 1, so we can forgive it */
    long long card_duplicate = card_number / 10;

    // counts digits */
    int no_digits = floor(log10(card_number)) + 1;
    if (no_digits != 13 && no_digits != 15 && no_digits != 16)
    {
        printf("INVALID\n");
        return 1;
    }
    // gets every second digit, then adds each digit of *each* number multiplied by 2 */
    for (int i = 0; i <= no_digits / 2; i++)
    {
        q = (card_duplicate % 10) * 2;
        card_duplicate = card_duplicate / 100;
        z += (q % 10) + ((q / 10) % 10);
    }
    // gets every second digit starting from rightmost (i.e all those not before, adds this to z (the total) */
    card_duplicate = card_number;
    for (int i = 0; i <= (no_digits / 2); i++)
    {
    q = (card_duplicate) % 10;
    card_duplicate = card_duplicate / 100;
    z += q;
    }

    // if final digit equals 0, the card number is valid
    if (z % 10 == 0)
    {
    for (int i = 0; i < no_digits - 2; i++) {
    card_number = card_number / 10;
    }

    if (card_number == 34 || card_number == 37)
    {
        printf("AMEX\n");
        return 0;
    }
    else if (card_number >= 51 && card_number <= 55)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((card_number / 10) == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else {
        printf("INVALID\n");
        return 1;
    }

    }
    }
    while (1 < 2);

    return 1;
}