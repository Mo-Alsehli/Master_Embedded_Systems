# This project is based on the STM32F103C6 With Cortex-M3 Processor.
![image](https://github.com/Mo-Alsehli/Master_Embedded_Systems/assets/98949843/877509c1-fb1f-4872-b81e-bfa2c1e7ee5e)

## The main objective of this project is to enable and configure external interrupt EXTI0.

### Tools

1. STM32 Cube IDE.
2. Keil Micro-Vision Simulator.

### Main Registers That Are Used To Configure External Interrupt EXTI0
1. RCC & RCC_APB2ENR -> reset clock control for enabling APB2 Clock.
2. GPIOA -> general input and output register PORTA.
3. EXTI -> External Interrupt Register.
4. AFIO -> Alternative Function Input Output Register.

### Procedure
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

#### Simulation
![Simulation](https://drive.google.com/file/d/1uUkbZ6L9HO5J31lSIFfCq7td6nNySirZ/view?usp=sharing)
