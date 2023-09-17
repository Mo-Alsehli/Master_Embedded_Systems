/*
 * main.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Mohamed Magdi
 */

#include "DIO.h"

void wait(int time){
	int i, j;
	for(i = 0; i < time; i++){
		for(j = 0; j < 255; j++);
	}
}

void display3LedBuzzer() {
	SetPin(PORTD, 5);
	wait(600);
	ClearPin(PORTD, 5);
	SetPin(PORTD, 6);
	wait(600);
	ClearPin(PORTD, 6);
	SetPin(PORTD, 7);
	wait(600);
	ClearPin(PORTD, 7);
	SetPin(PORTD, 4);
	wait(600);
	ClearPin(PORTD, 4);
}

void display7Segements() {
	int i, j;
	// Configure PORTC Pins As Output.
	DDRC = 0xff;
	// Display 7-segments
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			PORTC = 0b1011 | (i << 4);
			wait(500);
			PORTC = 0b0111 | (j << 4);
			wait(200);
		}
	}
}

int main() {
	// Set PortD PIN 4, 5, 6, 7 As Output
	int i;
	for(i = 0; i < 4; i++){
		SetPin(DDRD, (i + 4));
		//SetPin(PORTD, (i + 4));
	}

	while(1){
		display3LedBuzzer();
		display7Segements();
	}
}


