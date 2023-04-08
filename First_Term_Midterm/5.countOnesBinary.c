/* 
5.countOnesBinary.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

int countOnesBinary(int num){
    int result = 0;

    while(num > 0){
        int rem = num % 2;
        result += rem;
        num /= 2;
    }

    return result;
}

int main() {
    printf("\n######### Program-5 ###########\n");
    printf("C Program To Count Number Of Ones In Binary Number \n\n");

    int num;
    printf("Input: ");
    scanf("%d", &num);

    printf("Output: %d \n\n", countOnesBinary(num));

    return 0;
}