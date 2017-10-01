#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!(isalpha(argv[1][i]))) {
            printf("Error: key must not contain non-alphabetical characters.\n");
            return 1;
        }
    }
    // get encryption key
    char *s_key = argv[1];
    
    printf("plaintext: ");

    // get plaintext
    char *s_text = get_string();
    int k = 0;
    
    printf("ciphertext: ");
    // iterate through plaintext
    for (int i = 0; i < strlen(s_text); i++)
    {
        // loops through chars in the key
        int j = (i - k) % strlen(s_key);
        
        // print non-alhabetical characters (spaces etc)
        if ((s_text[i] > 90 && s_text[i] < 97) || s_text[i] < 65 || s_text[i] > 122) {
            printf("%c", s_text[i]);
            // makes sure j won't increment (with an offset)
            k += 1;
        }
        
        // prints shifted uppercase chars
        else if (s_text[i] >= 65 && s_text[i] <= 90) {
            printf("%c", ((((s_text[i] - 65) + (toupper(s_key[j]) - 65)) % 26) + 65));
        }
        
        // prints shifted lowercase chars
        else if (s_text[i] >= 97 && s_text[i] <= 122) {
            printf("%c", ((((s_text[i] - 97) + (toupper(s_key[j]) - 65)) % 26) + 97));

        }
    }
    printf("\n");
}