#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CMD_ARGUMENTS 2


int main(int argc, char *argv[])
{

    if (argc != CMD_ARGUMENTS) {
        printf("Error, usage: ./caesar k\n");
        return 1;
    }

    printf("plaintext: ");
    char *s = get_string();
    int alpha_shift = (atoi(argv[1]) % 26);

    printf("ciphertext: ");

    /*iterate through plaintext */
    for (int i = 0; i < strlen(s); i++) {

        /* print char unchanged if not alphabetical */
        if ((s[i] > 90 && s[i] < 97) || s[i] < 65 || s[i] > 122) {
            printf("%c", s[i]);
        }

        /* if char is uppercase, shift it by specified int */
        else if (s[i] >= 65 && s[i] <= 90) {
            printf("%c", (((s[i] - 65) + alpha_shift) % 26) + 65);
        }

        /* if char is lowercase, shift it by specified int */
        else if (s[i] >= 97 && s[i] <= 122) {
            printf("%c", (((s[i] - 97) + alpha_shift) % 26) + 97);
        }
    }
    printf("\n");
}