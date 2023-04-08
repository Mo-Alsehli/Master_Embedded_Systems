/* 
4.reverseDigits.c
author: Mohamed Magdi
date: 8 April 2023
*/
#include <stdio.h>

int reverseDigits(int num){
    int reversed = 0;

    while(num > 0){
        int rem = num % 10;
        reversed = reversed * 10 + rem;
        num /= 10;
    }
    return reversed;
}


int main() {
    printf("############# Program-4 ##############\n");
    printf("C Program To Reverse Digits In A Number \n\n");

    int num;
    printf("Input: ");
    scanf("%d", &num);

    printf("Output: %d\n\n", reverseDigits(num));


    return 0;
}