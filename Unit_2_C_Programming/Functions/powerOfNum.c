#include <stdio.h>


int calcPower(int num, int exp) {
    int power = 1;

    if(exp == 0){
        return 1;
    }else{
        return num * calcPower(num, exp - 1);
    }
}


int main() {

    printf("Program-4\n\n");
    printf("C Program To Calculate The Power Of A Number Using Recursion:\n");

    int num, exp;

    printf("Enter Base Number: ");
    scanf("%d", &num);

    printf("Enter Power Number (Positive Integer): ");
    scanf("%d", &exp);

    printf("The Power %d Of Base %d Is: %d", exp, num, calcPower(num, exp));

    printf("\n\n");


    return 0;
}