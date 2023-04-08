/* 
7.sumFrom1to100.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

/* 
-- Logical Formula To Find The Sum Of Numbers From 'start' to 'end'.
-- sum = (start + end) * (numberOfElements) / 2
- For our program:
-- sum = (1 + 100) * 100 / 2
*/

int sumFrom1To100() {
    int sum = (1 + 100) * 100 / 2;
    return sum;
}

int main() {

    printf("\n########### Program-7 ###########\n");
    printf("C Program To Sum Numbers From 1 To 100 Without Loop\n\n");

    printf("The Sum Of Numbers From 1 To 100 Without A Loop Is: %d \n\n", sumFrom1To100());

    return 0;
}