#include <stdio.h>

/*
-- How to get the object file of a library:
-> gcc -c file.c -o file.o
-> ./ar.exe rcs lib_file.a can.o
-- The lib_file.a is the static library file that we will provide the customer with.
*/

void can_init()
{
    printf("CAN INIT >>>>>>>>>>>>>>>>>>>> \n");
}