/* 
1.sumAllDigits.c
author: Mohamed Magdi
Date: 8 April 2023
*/

#include <stdio.h>
#include <math.h>



int isPrime(int num){
    if(num < 2){
        return 0;
    }
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

void primeNumbersBetweenIntervals(void){

    int interval1, interval2, i;
    printf("Enter TWo Numbers (Intervals): \n");
    scanf("%d %d", &interval1, &interval2);

    printf("Prime Numbers Between %d and %d are: ", interval1, interval2);
    for(i = interval1 + 1; i < interval2; i++){
        if(isPrime(i) == 1){
            printf("%d  ", i);
        }
    }

}

int main() {

    printf("Program-3\n\n");
    printf("C Program To Calculate Prime Numbers Between Two Intervals by Making User Defined Function: \n");

    primeNumbersBetweenIntervals();

    printf("\n\n"); 
    


    return 0;
}