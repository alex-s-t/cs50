/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
#include <stdio.h>
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0 || value < values[0]) {
        return 0;
    }
    
    int last = (n * 4) / sizeof(values[0]) - 1;
    
    if (value > values[last]) {
        return 0;
    }
    
    int max = n - 1; // max index of array that we should bother with
    int min = 0; // min index of array to bother with
    int j = n / 2; // initial starting point (middle of the array)
    
    do {
        
    // will only return 1 if value is equal to j !
    if (values[j] == value) {
        return 1;
    }

    // means we are at the 'end' of the binary search, only one element was left and that check failed in the previous if block
    else if (max == min || max < min || min > max) {
        break;
    }
    
    // if the target value is less than the value at array[j]...
    else if (values[j] > value) {
        // we set the max index of the array that should now be ever searched to
        max = j - 1;
        
        // and set j to the middle of min and max variables
        j = min + ((max - min) / 2);
    }
    
    // if the target value is greater than the value at array[j]...
    else if (values[j] < value) {
        // we set the min index of the array that should now ever be searched to
        min = j + 1;
        
        // and set j to the middle of min and max variables
        j = min + ((max - min) / 2);
    }
    
    }
    while (1 < 2);
    // item not in list on any break
    return 0;

}

/**
 * Sorts array of n values. counting sort (O(n)), but keep in mind that n should be nothing too big...
 */
void sort(int values[], int n)
{
    // initialise a rather gigantic array...
    int array_counter[65537] = { 0 };
    int store;
    int q = 0;
    
    // 
    for (int i = 0; i < n; i++) {
        store = values[i];
        array_counter[store] += 1;
    }
    
    for (int i = 0; i < 65537; i++) {
        for (int j = 0; j < array_counter[i]; j++) {
            values[q] = i;
            q += 1;
        }
    }

    return;

}
