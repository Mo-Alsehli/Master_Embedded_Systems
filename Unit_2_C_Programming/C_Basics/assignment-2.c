/* 
assignment-2.c
date: 22 Mar 2023
author: Mohamed Magdi
 */


#include <stdio.h>



int main() {

    // Write A Number To Check Whether A Number Is Even Or Odd.
    printf("Program-1 / Write A Number To Check Whether A Number Is Even Or Odd. \n\n");
    int num = 0;
    for(int i = 0; i < 2; i++){
        printf("Output-%d \n", i + 1);
        printf("Enter an integer you want to check: ");
        scanf("%d", &num);
        if(num % 2 == 0){
            printf("%d is Even \n", num);
        }else if(num % 2 == 1){
            printf("%d is Odd \n", num);
        }
        printf("\n\n");
    }

    // C Program To Check Vowel Or Consonant.
    printf("Program-2 / C Program To Check Vowel Or Consonant. \n\n");

    char ch = 'a';
    for(int i = 0; i < 2; i++){
        printf("Output-%d \n", i + 1);
        printf("Enter An Alphabet: ");
        scanf(" %c", &ch);
        switch(ch){
            case 'a':
            case 'A':
                printf("%c is Vowel \n", ch);
            break;
            case 'e':
            case 'E':
                printf("%c is Vowel \n", ch);
            break;
            case 'i':
            case 'I':
                printf("%c is Vowel \n", ch);
            break;
            case 'o':
            case 'O':
                printf("%c is Vowel \n", ch);
            break;
            case 'u':
            case 'U':
                printf("%c is Vowel \n", ch);
            break;
            default:
                printf("%c is consonant\n", ch);
        }
        printf("\n \n");
    }


    // C Program To Find The Largest Number Among 3 Numbers
    printf("Program-3 / C Program To Find The Largest Number Among 3 Numbers \n\n");
    int a = 0, b = 0, c = 0;
    printf("Enter Three Numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if(a > b){
        if(a > c){
            printf("Largest Number = %d \n", a);
        }else {
            printf("Largest Number = %d \n", c);
        }
    }else {
        if(b > c){
            printf("Largest Number: %d \n", b);
        }else {
            printf("Largest Number = %d \n", c);
        }
    }
    printf("\n \n");


    // C Program To Check Whether Number Is Positive Or Nigative:
    
    printf("Program-4 / C Program To Check Whether Number Is Positive Or Nigative: \n\n"); 
    int num1 = 0;
    for(int i = 0; i < 2; i++){
        printf("Output-%d\n", i + 1);
        printf("Enter A Number: ");
        scanf("%d", &num1);
        if(num1 > 0){
            printf("%d is positive\n", num1);
        }else if(num1 < 0){
            printf("%d is negative\n", num1);
        }else{
            printf("You Entered Zero.\n");
        }
        printf("\n\n");
    }
    

    // C Program To Check Whether A Character Is Alphabet Or Not.
    printf("Program-5 / C Program To Check Whether A Character Is Alphabet Or Not. \n\n");
    char ch1 = 'A';
    for(int i = 0; i < 2; i++){
        printf("Output-%d\n", i + 1);
        printf("Enter A Character: ");
        scanf(" %c", &ch1);
        if((ch1 >= 65 && ch1 <= 90) || (ch1 >= 97 && ch1 <= 122)){
            printf("%c Is Alphabet\n", ch1);
        }else {
            printf("%c Is Not Alpahbet\n", ch1);
        }
        printf("\n \n");
    }


    // C Program To Calculate The Sum Of Natural Numbers.
    printf("Program-6 / C Program To Calculate The Sum Of Natural Numbers \n \n");

    int n = 0, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    printf("Sum = %d", sum);
    printf("\n \n");


    // C Program To Find Factorial Number.
    printf("Program-7 / C Program To Find Factorial Number. \n \n");
    for(int j = 0; j < 2; j++){
        int num2 = 0, factorial = 1;
        printf("Output-%d: \n", j + 1);
        printf("Enter an integer: ");
        scanf("%d", &num2);
        if(num2 < 0){
            printf("Error!!! Factorial of negative number doesn't exist");
        }else {
            for(int i = 1; i <= num2; i++){
                factorial *= i;
            }
            printf("Factorial = %d", factorial);
        }
        printf("\n \n");
    }


    // Simple C Program To Make A Simple Calculator To Add, Subtract, Multiply, or Divide Using Switch Case.

    printf("Program-8 / Simple C Program To Make A Simple Calculator To Add, Subtract, Multiply, or Divide Using Switch Case. \n \n");

    float n1 = 0, n2 = 0;
    char operator;
    printf("Enter Operator Either +, -, * Or /: ");
    scanf(" %c", &operator);
    printf("Enter Two Operands: ");
    scanf(" %f %f", &n1, &n2);

    switch (operator)
    {
    case '+':
        printf("%.1f + %.1f = %.1f\n", n1, n2, n1 + n2);
        break;
    case '-':
        printf("%.1f - %.1f = %.1f\n", n1, n2, n1 - n2);
        break;
    case '*':
        printf("%.1f * %.1f = %.1f\n", n1, n2, n1 * n2);
    case '/':
        printf("%f / %.1f = %.1f\n", n1, n2, n1 / n2);
    default:
        break;
    }

    return 0;
}