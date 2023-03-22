/* 
assignment-1.c
date: 22 Mar 2023
author: Mohamed Magdi
*/


#include <stdio.h>



int main() {
    printf("#####Home_work-1############### \n\n");
/* 
#####Home_work-1###############

EX1:

Write C Program to Print a Sentence

i should see the Console as following:
##########Console-output###
C Programming
###########################

########################################################################
*/
printf("EX1: \n");
printf("##########Console-output### \n");
printf("C Programming \n");
printf("########################### \n\n");


/* 
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
###########################

######################################################################## 
*/

printf("EX2: \n");

int a = 0;

printf("##########Console-output### \n");

printf("Enter An Integer: ");
scanf("%d", &a);
printf("You Entered: %d \n", a);

printf("########################### \n\n");

/* 
EX3:

Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
###########################

########################################################################
*/

printf("EX3: \n");

int b = 0;
printf("##########Console-output###\n");

printf("Enter Two Numbers: ");
scanf("%d %d", &a, &b);
printf("Sum: %d \n", a + b);

printf("########################### \n \n");


/* 
EX4:

Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###

###########################
Enter two numbers: 2.4
1.1
Product: 2.640000
########################################################################
*/

printf("EX4: \n");

float c = 0, d = 0;
printf("##########Console-output### \n");

printf("Enter Two Numbers: ");
scanf("%f %f", &c, &d);
printf("Product: %f \n", c * d);

printf("########################### \n \n");


/* 
EX5:

Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################


########################################################################
*/

printf("EX5: \n");

char ch = 'A';

printf("#########Console_output###### \n");

printf("Enter A Character: ");
fflush(stdin);
scanf(" %c", &ch);
printf("ASCII Value Of %c = %d \n", ch, ch);

printf("########################### \n \n");


/* 
EX6:

Write Source Code to Swap Two Numbers

#########Console_output######
Enter value of a: 1.20
Enter value of b: 2.45

After swapping, value of a = 2.45
After swapping, value of b = 1.2
#############################
########################################################################
*/


printf("EX6: \n");

printf("#########Console_output###### \n");

printf("Enter A Value Of a: ");
scanf("%f", &c);
printf("Enter A Value Of b: ");
scanf("%f", &d);

float temp = c;
c = d;
d = temp;

printf("After swapping, value of a = %.2f\n", c);
printf("After swapping, value of b = %.2f\n", d);

printf("########################### \n \n");


/* 
EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
*/

printf("EX7: \n");

int first = 10, second = 20;

printf("#########Console_output###### \n");

printf("Before Swapping: first = %d, second = %d \n", first, second);

first = first ^ second;
second = first ^ second;
first = first ^ second;

printf("After Swapping: first = %d, second = %d \n", first, second);

printf("########################### \n");

    return 0;
}