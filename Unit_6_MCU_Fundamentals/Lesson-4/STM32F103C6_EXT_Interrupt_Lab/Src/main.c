/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Magdi
 * @brief          : Main program body
 ******************************************************************************
 **/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

// Reset And Clock Control Register
#define RCC_Base 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_Base + 0x18)

// GPIO BASE
#define GPIOA_Base 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_Base + 0x04)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_Base + 0x00)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_Base + 0x0C)

/*
 •  To generate the interrupt, the interrupt line should be configured and enabled. This is done
	by programming the two trigger registers with the desired edge detection and by enabling
	the interrupt request by writing a ‘1’ to the corresponding bit in the interrupt mask register.
	When the selected edge occurs on the external interrupt line, an interrupt request is
	generated. The pending bit corresponding to the interrupt line is also set. This request is
	reset by writing a ‘1’ in the pending register.
 •  Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
 •  Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR and
    EXTI_FTSR)
 •  Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
    External Interrupt Controller (EXTI) so that an interrupt coming from one of the 20 lines
    can be correctly acknowledged.
 */
// EXTI Register
#define EXTI_Base 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_Base + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_Base + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_Base + 0x14)


// Alternative Function I/O Register
#define AFIO_Base 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_Base + 0x08)

// NVIC BASE
#define NVIC_EXTIE0 *(volatile uint32_t*)(0xE000E100)

void clockInit(void) {
	// Enable Clock For AFIO Register
	RCC_APB2ENR |= (1<<0);
	// Enable Clock For GPIOA Register
	RCC_APB2ENR |= (1<<2);
}

void gpioInit(void) {
	// Pin_13 PORTA As Output.
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	// Pin_0 PORTA As Input: Floating Input (Floating means it's not connected with anything as we will connect it with a push button).
	GPIOA_CRL |= (1<<2);
}


int main(void)
{
	clockInit();
	gpioInit();

	// Mask Interrupt for line0
	EXTI_IMR |= (1<<0);

	// Configure The trigger selection to be rising edge.
	EXTI_RTSR |= (1<<0);

	// AFIO_EXTICR1 Is Set To Zero So that the Source Input Is For PA pin.
	AFIO_EXTICR1 = 0;

	// Enable NVIC Irq6(from Interrupt Vector Table)   <<>> EXTI0
	NVIC_EXTIE0 |= (1 << 6);

	while(1);
}

void EXTI0_IRQHandler(void) {
	GPIOA_ODR ^= (1 << 13);

	EXTI_PR |= (1 << 0);
}
