/* 
3.reverseArr.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

void reverseArr(int arr[], int size){
    if(size > 0){
        printf("%d ", arr[size - 1]);
        reverseArr(arr, size - 1);
    }
}

int main(){

    printf("\n########### Program-8 ###########\n");
    printf("C Program To Reverse Array Elements \n\n");

    int arr[5] = {1, 2, 3, 4, 5};
    printf("Input: {1, 2, 3, 4, 5}\n\n");

    printf("Output: ");
    reverseArr(arr, 5);
    printf("\n\n");

    return 0;
}