# This project is based on the ATmeg32 Board.
![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/a3437971-70e5-41e3-97c9-aa531ff6dfdc)

## The main objective of this project is to enable and configure external interrupts INT0, INT1, and INT2 in ATmega32.

### Tools

1. Eclipse With AVR Plugin.
2. Proteus Simulator.
3. Avr-gcc.

### Main Registers That Are Used To Configure External Interrupts
1. DDRD -> direct data register that is responsible for accessing the bits as inputs.
2. PORTD -> portd register that is responsible for writing on bits that are configured as an input.
3. SREG -> status register for enabling global interrupts.
4. MCUCR & MCUCSR -> MCU control register that controls the modes for interrupts.
5. GICR -> general interrupt control register that is responsible for enabling interrupt requests.

### Main Goal For This Project:
1. INT0 sends 1 to PortD Pin_5 when any logical change.
2. INT1 sends 1 to PORTD Pin_6 when rising edge.
3. INT2 sends 1 to PORTD Pin_7 when falling edge.

#### Simulation

https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/05d2bca4-83f2-45ab-a83b-2fd4a1698af0

