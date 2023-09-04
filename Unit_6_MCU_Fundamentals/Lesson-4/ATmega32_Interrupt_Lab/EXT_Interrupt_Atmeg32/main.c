/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Mohamed Magdi
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
	// Enable Global Interrupt.
	SREG |= (1 << 7);
	// Configuring PortD Pin_5,6,7 As Output Pins And The rest of register pins are configured as input pins:
	DDRD |= (1 << 5);
	DDRD |= (1 << 6);
	DDRD |= (1 << 7);

	// Configure Pin_2 And Pin_3 In PortD As Input
	DDRD &= ~(1 << 2);
	DDRD &= ~(1 << 3);

	// Configuring PortB Pin_2 as Input Pin:
	DDRB &= ~(1 << 2);

	// INT0 generate interrupt request when any logical change
	MCUCR |= (1 << 0);
	MCUCR &= ~(1 << 1);
	// INT1 generate interrupt request when rising edge
	MCUCR |= (1 << 2);
	MCUCR |= (1 << 3);

	// If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
	MCUCSR &= ~(1 << 6);

	// GICR: INT2: External Interrupt Request 2 Enable
	GICR |= (1 << 5);
	// GICR: INT0: External Interrupt Request 0 Enable
	GICR |= (1 << 6);
	// GICR: INT1: External Interrupt Request 1 Enable
	GICR |= (1 << 7);



	while (1){
		PORTD &= ~(1 << 5);
		PORTD &= ~(1 << 6);
		PORTD &= ~(1 << 7);
	}

}

ISR(INT0_vect)
{
	PORTD |= (1 << 5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	PORTD |= (1 << 6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	PORTD |= (1 << 7);
	_delay_ms(1000);
}

