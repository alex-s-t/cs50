#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


/* constants */
#define MAX_PW_LENGTH 5
#define SALT_LENGTH 3

#define MIN_CMD_ARGUMENTS 2

#define SUCCESS 0
#define FAILURE 1

#define PW_FOUND 2
#define PW_NOT_FOUND 0


/* function prototype */
int string_comparer(char *q, char *s, char *salt);


/* where all the fun stuff happens */
int main(int argc, char *argv[])
{

    if (argc != MIN_CMD_ARGUMENTS) {
        printf("Usage: ./crack hash\n");
        return FAILURE;
    }

    char *s = argv[1];
    char salt[SALT_LENGTH] = {'5', '0', '\0'};
    char test_string [MAX_PW_LENGTH] = { '\0' }; test_string[0] = 'a';

    int length = 0;
    int i = 0;
    int j = 0;

    while (strlen(test_string) < MAX_PW_LENGTH) {


        length = strlen(test_string);

        /* check to see if max combinations achieved (all 'Z' in array) */
        for (i = 0; i < length; i++) {
            if (test_string[i] != 'Z') {
                break;
            }
            for (j = 0; j < length + 1; j++) {
                test_string[j] = 'a';
            }
        }

        /* iterate through word */
        for (i = length - 1; i > -1; i--) {
            /* if this condition is true, but the ones following it are not,
            it's the only case in which the for loop will continue */
            if (test_string[i] == 'Z') {
            test_string[i] = 'a';

                /* check if preceding letter needs to be changed
                ** (any letter preceding a Z that isn't itself Z) */
                if (test_string[i - 1] != 'Z') {
                    if (test_string[i - 1] == 'z') {
                        test_string[i - 1] = 'A';
                        break;
                    }
                    /* if it's not a Z, safe to change i - 1.
                    ** Otherwise we'll iterate around again. */
                    else {
                        test_string[i - 1] = test_string[i - 1] + 1;
                        break;
                    }
                }
            }

            /* this will only trigger if the first
            ** letter checked isn't an uppercase Z. */
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

        /* test the target string */
        if (string_comparer(test_string, s, salt)) {
            printf("%s\n", test_string);
            return SUCCESS;
        }


    }
    /* end while loop */
}


/* compares input string to encrypted's string output */
int string_comparer(char *q, char *s, char *salt)
{

    int i = 0;
    char *string_enc = crypt(q, salt);

    for (i = 0; i < strlen(s); i++) {
        if (s[i] != string_enc[i]) {
            return PW_NOT_FOUND;
        }
    }
    return PW_FOUND;
}