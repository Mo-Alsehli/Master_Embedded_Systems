#include <stdio.h>
#include <math.h>
#include <string.h>


// Program-1:

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


// Program-2

int factorial(int n){
    if(n < 2){
        return 1;
    }
    return n * factorial(n - 1);
}



int main() {

    printf("Program-1\n\n");
    printf("EX1: Prime Numbers Between Two Intervals by Making User Defined Function: \n");

    primeNumbersBetweenIntervals();

    printf("\n\n"); 


    printf("Program-2\n\n");
    printf("EX2: C Program To Calculate Factorial Of A Number Using Recursion: \n");

    int n;
    printf("Enter An Integer: ");
    scanf("%d", &n);

    printf("The Factorial Of %d Is: %d\n", n, factorial(n)); 
    
 

    return 0;

}