/*
assignment.c
author: Mohamed Magdi
date: 30 April 2023
*/
#include <stdio.h>
#include <string.h>

// Program-3
void reverse(char *str);

// Program-5
struct SEmployee
{
    char *name;
    int ID;
};

int main()
{
    printf("\n############## Program-1 ##############\n");
    printf("Write a program in C to demonstrate how to handle the pointers in the program.\n\n");

    int m = 29;
    printf("Address of m: 0X%X\nValue of m: %d\n", &m, m);

    int *ab = &m;
    printf("\nNow ab is assigned with address of m.\n");
    printf("Address of pointer ab: 0X%X\nContent of pointer ab: %d \n", ab, *ab);

    m = 34;
    printf("\nThe value of m assigned to 34 now.\n");
    printf("Address of ab: 0X%X\nContent of ab: %d\n", ab, *ab);

    *ab = 7;
    printf("\nThe value of ab is assigned with value 7 now.\n");
    printf("address of m: 0X%X\nValue of m: %d\n\n", &m, m);
    printf("\n\n");

    // #####################################################################################################

    printf("########### Program-2 ############\n");
    printf("Write a program in C to print all the alphabets using a pointer.\n\n");

    char letters[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
    char *alpha = letters;
    while (*alpha != '\0')
    {
        printf("%c  ", *alpha);
        alpha++;
    }
    printf("\n\n");

    // #####################################################################################################

    printf("############# Program-3 ##############\n");
    printf("Write a C program to print a string in reverse using a pointer.\n\n");

    char str[100];

    printf("Input a string: ");
    scanf("%s", str);

    reverse(str);

    printf("Reverse of the string is: %s\n\n", str);
    printf("\n");

    // #####################################################################################################

    printf("############ Program-4 #############\n");
    printf("Write a program in C to print the elements of an array in reverse order.\n\n");

    int arr[15];
    int num, *numsPtr = arr;
    printf("Input the number of elements to store in the array (max 15): ");
    scanf("%d", &num);

    printf("Input %d number of elements in the array: \n", num);
    for (int i = 0; i < num; i++)
    {
        printf("element-%d: ", i + 1);
        scanf("%d", &arr[i]);
        numsPtr++;
    }

    printf("\nExpected Output: \n");
    printf("The elements of array in reverse order are: \n");
    while (num > 0)
    {
        numsPtr--;
        printf("element-%d: %d\n", num, *numsPtr);
        num--;
    }
    printf("\n\n");

    // #####################################################################################################

    printf("############# Program-5 #############\n");
    printf("Write a program in C to show a pointer to an array which contents are pointer to structure.\n\n");

    // Structure Variable.
    struct SEmployee emp1 = {"Alex", 1002};
    struct SEmployee emp2 = {"Mohamed", 1003};
    // Pointer To Structre.
    struct SEmployee *empPtr1 = &emp1;
    struct SEmployee *empPtr2 = &emp2;
    // Array of pointers to structure.
    struct SEmployee *arrEmpPtr[] = {empPtr1, empPtr2};

    printf("Expected Output: \n");
    for (int i = 0; i < 2; i++)
    {
        printf("Employee Name: %s\n", arrEmpPtr[i]->name);
        printf("Employee ID: %d\n\n", arrEmpPtr[i]->ID);
    }
    printf("\n\n");

    return 0;
}

// Program-3
void reverse(char *str)
{
    char *start, *end;
    char temp;

    start = str;
    end = str + strlen(str) - 1;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}