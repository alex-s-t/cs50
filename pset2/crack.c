#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int string_comparer(char *q, char *s, char *salt);

int main(int argc, char *argv[])
{
    
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char *s = argv[1];
    char salt[3] = {'5', '0', '\0'};
    char test_string [5] = { '\0' }; test_string[0] = 'a';
    int length;
    
    while (strlen(test_string) < 5) {

        length = strlen(test_string);
        // check to see if max combinations achieved (all 'Z' in array for given length)
        for (int i = 0; i < length; i++) {
            if (test_string[i] != 'Z') {
                break;
            }
            for (int j = 0; j < length + 1; j++) {
                test_string[j] = 'a';
            }
        }
        
        // iterate through word
        for (int i = length - 1; i > -1; i--) {
            // if this condition is true, but the ones following it are not, it's the only case in which the for loop will continue
            if (test_string[i] == 'Z') {
            test_string[i] = 'a';
            
                // check if preceding letter needs to be changed (any letter preceding a Z that isn't itself Z)
                if (test_string[i - 1] != 'Z') {
                    if (test_string[i - 1] == 'z') {
                        test_string[i - 1] = 'A';
                        break;
                    }
                    // if it's not a Z, safe to change i - 1. Otherwise we'll iterate around again.
                    else {
                        test_string[i - 1] = test_string[i - 1] + 1;
                        break;
                    }
                }
            }
            
            // this will only trigger if the first letter checked isn't an uppercase Z.
            else {
                if (test_string[i] == 'z') {
                    test_string[i] = 'A';
                    break;
                }
                else {
                    test_string[i] = test_string[i] + 1;
                    break;
                }
            }
        }
        
    if (string_comparer(test_string, s, salt)) {
        printf("%s\n", test_string);
        return 0;
    }


    }
    // end while loop
    
}

// function for comparing input string to encrypted's string output
int string_comparer(char *q, char *s, char *salt)
{
    char *string_enc = crypt(q, salt);
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != string_enc[i]) {
            return 0;
        }
    }
    return 1;
}