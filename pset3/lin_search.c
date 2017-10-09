#include <stdio.h>

// implementation of linear search
int main(void)
{
    // oredered or not! array of values to search
    int values[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};
    int array_length = 23;
    int target = 83;
    // pretend that I'm actually doing work here
    // search each element one by one...
    for (int i = 0; i < array_length; i++) {
        if (values[i] == target) {
            printf("Your value: (%i), is in the list at index: %i", target, i);
            return 1;
        }
    }
    // default to returning 0 if nothing found
    printf("Your value: (%i), is not in the list.", target);
    return 0;
}