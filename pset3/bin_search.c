#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

bool search(int n, int values[], int size);

int main(int argc, char *argv[]) {
    
    int values[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 10000};
    if (argc != 2) {
        printf("usage: ./bin_search target\n");
        return 1;
    }
    int n = atoi(argv[1]);
    int size = 24;
    
    if (search(n, values, size)) {
        printf("Your value is in the list.\n");
        return 0;
    }
    else {
        printf("Your value is not in the list.\n");
        return 0;
    }
}

// implementation of binary search - doesn't actually sort (that's in another file somewhere around here)
bool search(int n, int values[], int size)
{

    // int values[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};
    // int size = 23
    size_t max = size - 1; // max index of array that we should bother with
    size_t min = 0; // min index of array to bother with
    size_t j = size / 2; // initial starting point (middle of the array)
    
    //do {
    
    while (max != min || min > max || max < min) {
        

    if (values[j] == n) {
        return 1;
    }

    else if (values[j] > n) {
        max = j - 1;
        j = (max + min) / 2;
    }

    else if (values[j] < n) {
        min = j + 1;
        j = (max + min) / 2;
    }
    
    }
    //while (1 < 2);

    if (values[j] == n) {
        return 1;
    } 
    
    return 0;

}