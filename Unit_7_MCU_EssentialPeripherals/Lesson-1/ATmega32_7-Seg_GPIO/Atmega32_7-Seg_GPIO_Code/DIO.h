/*
 * DIO.h
 *
 *  Created on: Sep 17, 2023
 *      Author: dell
 */

#ifndef DIO_H_
#define DIO_H_

// PORTC
#define PORTC *((volatile unsigned char*) 0x35)
#define DDRC *((volatile unsigned char*) 0x34)
#define PINC *((volatile unsigned char*) 0x33)

// PORTD
#define PORTD *((volatile unsigned char *) 0x32)
#define DDRD *((volatile unsigned char *) 0x31)
#define PIND *((volatile unsigned char *) 0x30)



#define SetPin(reg, pin) (reg |= (1 << pin))
#define ClearPin(reg, pin) (reg &= ~(1 << pin))
#define TogglePin(reg, pin) (reg ^= (1 << pin))
#define ReadPin(reg, pin) (reg >> pin & 1)


#endif /* DIO_H_ */
