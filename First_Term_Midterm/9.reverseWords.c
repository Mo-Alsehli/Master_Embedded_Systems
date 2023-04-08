/* 
9.reverseWords.c
author: Mohamed Magdi
date: 8 April 2023
*/

#include <stdio.h>

void reverseWords(char str[], int size){
    int i = 0;
    if(size > 0){
        while(str[i] != ' '){
            i++;
        }
        i++;
        reverseWords(str + i , size - i);
        printf("%.*s", i, str);
        printf(" ");
    }
}

int main() {

    printf("\n########### Program-9 ########### \n");
    printf("C Program To Reverse Words In A String\n\n");

    char str[] = "mohamed magdi";
    int n = sizeof(str) / sizeof(str[0]);

    printf("Input-1: %s\n", str);
    printf("Output-1: ");
    reverseWords(str, n);

    printf("\n\n");

    char str2[] = "mohamed Gamal";
    n = sizeof(str2) / sizeof(str[0]);

    printf("Input-2: %s\n", str2);
    printf("Output-2: ");
    reverseWords(str2, n);

    printf("\n");

    return 0;
}