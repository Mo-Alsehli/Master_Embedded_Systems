#include "uart.h"

unsigned char str_buffer[100] = "learn-in-depth: Mohamed Magdi";

void main(void)
{
    UART_Send_Str(str_buffer);
}
