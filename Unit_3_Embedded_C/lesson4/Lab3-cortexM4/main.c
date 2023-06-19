/*
main.c - lab3 - cortexM4
author: Mohamed Magdi
20 June 2023
*/

#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long *)0x4002551C))

int main(void)
{
    volatile unsigned int i;
    // Enable System Control Register (GPIO Register)
    SYSCTL_RCGC2_R = 0x20;
    // Put some delay to insure that GPIO is running successfully.
    for (i = 0; i < 200; i++)
        ;
    // Put pin3 in PORTF register as output.
    GPIO_PORTF_DIR_R |= 1 << 3;
    GPIO_PORTF_DEN_R |= 1 << 3;

    while (1)
    {
        GPIO_PORTF_DATA_R |= 1 << 3;
        for (i = 0; i < 20000; i++)
            ;
        GPIO_PORTF_DATA_R &= ~(1 << 3);
        for (i = 0; i < 20000; i++)
            ;
    }

    return 0;
}
