#include <stdio.h>

int main(void)
{
    int values[] = {1, 2, 3, 6, 5, 6};
    int size = 6;
    int temp;
    int i;
    // using k, even though it's not actually necessary, to reduce iterations in the i loop
    int k;

    for (i = 1; i < size; i++) {
        k = i;
        while (k != 0 && values[k] < values[k - 1]) {
            temp = values[k - 1];
            values[k - 1] = values[k];
            values[k] = temp;
            k -= 1;
        }
    }
}