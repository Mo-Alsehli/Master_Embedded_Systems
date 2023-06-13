/*
main.c
Mohamed Magdi
12 June 2023
*/

#include <stdint.h>

// Registers Addresses:
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIO_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0c)

// Bit Fields
#define RCC_IOPAEN (1 << 2)
#define GPIOA13 (1UL << 13)

typedef union
{
    uint32_t all_fields;
    struct
    {
        uint32_t reserved : 13;
        uint32_t P_13 : 1;
    } Pin;
} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C);

int main(void)
{

    int i;
    // Enabling RCC Clock:
    RCC_APB2ENR |= RCC_IOPAEN;
    GPIO_CRH &= 0xFF0FFFFF;
    GPIO_CRH |= 0x00200000;

    while (1)
    {
        R_ODR->Pin.P_13 = 1;
        // Delay Loop
        for (i = 0; i < 10000; i++)
        {
        };

        R_ODR->Pin.P_13 = 0;
        // Delay Loop
        for (i = 0; i < 10000; i++)
        {
        };
    }

    return 0;
}
