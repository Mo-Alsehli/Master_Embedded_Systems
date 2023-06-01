#include "uart.h"

#define UART0DR *((volatile unsigned int *)(unsigned int *)0x101f1000)

void UART_Send_Str(unsigned char *p_str)
{
    while (*p_str != '\0')
    {
        UART0DR = (unsigned int)(*p_str);
        p_str++;
    }
}