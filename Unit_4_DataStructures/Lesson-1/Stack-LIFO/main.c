#include "lifo.h"
#include <stdio.h>

#define length 5
unsigned int buf1[length];

int main(void)
{
    LIFO_BUF_t lifo_buf1;
    Lifo_Init(&lifo_buf1, buf1, length);
    unsigned int temp;

    printf("\nAdding Elements To The Buffer\n\n");
    Lifo_Push_Item(&lifo_buf1, 5);
    Lifo_Push_Item(&lifo_buf1, 6);
    Lifo_Push_Item(&lifo_buf1, 7);
    printf("\n========================================\n\n");
    Lifo_IsEmpty(&lifo_buf1);
    printf("Lifo Top Is: %d\n", Lifo_Top_Item(&lifo_buf1));
    printf("\n========================================\n");

    printf("\nDeleteing Top Item From The Buffer\n");
    Lifo_Pop_Item(&lifo_buf1, &temp);
    printf("\tItem: %d deleted Successfully\n", temp);
    printf("\n========================================\n");

    printf("Lifo Top Is: %d\n", Lifo_Top_Item(&lifo_buf1));

    return 0;
}