#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // gets encryption key
    char *s_key = get_string();
    // gets encrypted text
    char *s_text = get_string();
    int k = 0;
    
    for (int i = 0; i < strlen(s_text); i++)
    {
        // loops through key
        int j = (i - k) % strlen(s_key);
        
        // print non-alhabetical characters (spaces etc.)
        if ((s_text[i] > 90 && s_text[i] < 97) || s_text[i] < 65 || s_text[i] > 122) {
            printf("%c", s_text[i]);
            k += 1;
        }
        
        // uppercase chars
        else if (s_text[i] >= 65 && s_text[i] <= 90) {
            int m = s_text[i] - 65;
            int g = (toupper(s_key[j])) - 65;
            // modulo in C, due to negative numbers
            int z = (((m - g) % 26) + 26) % 26; 
            printf("%c", z + 65);
        }
        
        // lowercase chars
        else if (s_text[i] >= 97 && s_text[i] <= 122) {
            int m = s_text[i] - 97;
            int g = (toupper(s_key[j])) - 65;
            int z = (((m - g) % 26) + 26) % 26;
            printf("%c", z + 97);

        }
    }
    
}