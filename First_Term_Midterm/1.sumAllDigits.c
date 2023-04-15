/* 
1.sumAllDigits.c
author: Mohamed Magdi
Date: 7 April 2023
*/

#include <stdio.h>

int sumAllDigits(int num);


int main() {
    printf("\n######### PROGRAM-1 ##########\n");
    printf("C Program To Take A Number And Sum All Digits");


    int num = 123;
    printf("Input: ");
    scanf("%d", &num);

    int sum = sumAllDigits(num);

    printf("Sum of %d Digits Is: %d\n\n", num, sum);



    return 0;
}

int sumAllDigits(int num){

    int sum = 0;
    while(num > 0){
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }

    return sum;
}