/* 
1.sumAllDigits.c
author: Mohamed Magdi
Date: 8 April 2023
*/

#include <stdio.h>
#include <math.h>

float square(int num){
    float ans = sqrt(num);

    return ans;
}


int main() {
    printf("\n############## Program-2 ##############\n");
    printf("C Program To Calculate The Square Root Of A Number: \n\n");

    int x;

    printf("Input: ");
    scanf("%d", &x);

    printf("The Square Root Of %d Is: %.3f \n\n", x, square(x));


    return 0;

}