#include <stdio.h>

int main(void)
{
    int values[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};
    int size = 23;
    int temp;
    int i;
    int tracker = 0;
    // using k, even though it's not actually necessary, to reduce iterations in the i loop

    for (i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (values[j] < values[j - 1]) {
                temp = values[j];
                values[j] = values[j - 1];
                values[j - 1] = temp;
                tracker = 1;
            }
        }
        
        // list already sorted, so no point iterating any more. :)
        if (tracker == 0) {
            break;
            }        
    }
    // end for loop
    
    for (i = 0; i < size; i++) {
        printf("%i\n", values[i]);
    }
}