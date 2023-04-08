/* 
6.uniqueNumbers.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

/* 
-- XOR Operation is canceled if we make and xor with the same value twice(a ^ b ^ b is equivilant to a).
-- Depending on that the function will only return unique element as the repeated elements will be removed from the XOR result.
-- If the repeated elements are repeated with odd number of repetitions we will need to XOR the result with the elements of the array once again.
-- Generally Remaking XOR operation will lead to the unique element finally whatever the number of repetitions is.
*/
int findUnique(int arr[], int size) {
    int result = 0;
    
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    
    return result;
}



int main() {
    printf("\n############ Program-6 ###########\n");
    printf("C Function To Return Unique Number In An Array With One Loop \n\n");

    int arr[7]={4, 2, 5, 2, 5, 7, 4};
    printf("Input-1: {4, 2, 5, 2, 5, 7, 4}\n");
    printf("Output-1: %d \n\n", findUnique(arr, 7));

    int arr1[3] = {4, 2, 4};
    printf("Input-2: {4, 2, 4}\n");
    printf("Output-2: %d \n\n", findUnique(arr1, 3));

    return 0;
}