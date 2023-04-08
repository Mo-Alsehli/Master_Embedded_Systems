/* 
6.uniqueNumbers2.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

void sortArr(int arr[], int n){
     int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int findUnique(int arr[], int size){
    sortArr(arr, size);
    int result, i;

    for(i = 0; i < size; i++){
        if(arr[i] != arr[i - 1] && arr[i] != arr[i + 1]){
            result = arr[i];
            break;
        }
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