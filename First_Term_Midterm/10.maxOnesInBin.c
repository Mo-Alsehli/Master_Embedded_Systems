/* 
10.maxOnesInBin.c
author: Mohamed Magdi
date: 8 April 2023
*/


#include <stdio.h>

int maxOnesInBin(int n){
    int maxCount = 0;
    int count = 0;
    while(n != 0) {
        if(n & 1) {
            count++;
        } else {
            count = 0;
        }
        if(count > maxCount) {
            maxCount = count;
        }
        n >>= 1;
    }
    return maxCount;
}

int main() {

    printf("\n########## Program-10 ############\n");
    printf("C Program To Count The Maximum Numbers Of Ones In A Binary Representation Of Given Number\n\n");

    int num = 14;

    printf("Input-1: %d\n", num);
    printf("Output-1: %d\n\n", maxOnesInBin(num));

    num = 110;
    printf("Input-1: %d\n", num);
    printf("Output-1: %d\n\n", maxOnesInBin(num));

    return 0;
}