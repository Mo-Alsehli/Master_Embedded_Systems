/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Magdi
 * @brief          : Main program body
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <core_cm3.h>


// register address
#define GPIOA_BASE 0x40010800

#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL *(volatile uint32_t *)(GPIOA_BASE + 0x00)

#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

// RCC - clock control register base:
#define RCC_Base 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_Base + 0x18)
#define RCC_CFGR *(volatile uint32_t *)(RCC_Base + 0x04)
#define RCC_CR *(volatile uint32_t *)(RCC_Base + 0x0)

// External Interrupt
#define EXTI_Base 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_Base + 0x0)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_Base + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_Base + 0x14)

// Alternative Function I/O Register Base
#define AFIO_Base 0x40010000
// External interrupt configuration register 1 (AFIO_EXTICR1)
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_Base + 0x08)

// NVIC BASE
#define NVIC_EXTIE0 *(volatile uint32_t*)(0xE000E100)

// =========================	OS	=============================

#define TASKA_SIZE		100
#define TASKB_SIZE		100
// switch from main stack to process stack pointer
#define SWTICH_MSP_TO_PSP()	__asm volatile("mrs	r1, control \n\t\
											mov r2, #2 \n\t\
											orr	r1,r1,r2 \n\t\
											msr control, r1");
// switch from process stack to main stack pointer
#define SWTICH_PSP_TO_MSP()	__asm volatile("mrs	r1, control \n\t\
											mov r2, #5 \n\t\
											and	r1,r1,r2 \n\t\
											msr control, r1");

// Set process stack pointer to a specific address
#define SET_SP_TO_PSP(add)		__asm volatile("mov r1,%0	\n\t\
												msr PSP, r1": :"r"(add));
#define OS_Generate_Exception()	__asm volatile("SVC #3");


extern int _estack; // An Address
// start and end addresses for main stack pointer.
unsigned int _S_MSP;
unsigned int _E_MSP;
// start and end addresses for proccess stack pointer
// Task A
unsigned int _S_PSP_TaskA;
unsigned int _E_PSP_TaskA;
// Task B
unsigned int _S_PSP_TaskB;
unsigned int _E_PSP_TaskB;

enum accessLevel {
	privilege,
	unprivilege
};

// Flags
int irqFlag = 0, taskAFlag = 1, taskBFlag = 0;


// --- FUNCTIONS ---
// Processor Reset-Sequence Lab (Switch Privilege Level).
__attribute__((naked)) void switchAccessLevel(enum accessLevel level){
	switch(level){
	case privilege:
		// Clear Bit 0 in Control Register.
		__asm("mrs r2, CONTROL \n\t"
			  "mov r3, #0b11111110 \n\t"
			  "and r2, r3 \n\t"
			  "msr CONTROL, r2");
		break;

	case unprivilege:
		// Set Bit 0 in Control Register.
		__asm("mrs r2, CONTROL \n\t"
				"orr r2, #1 \n\t"
				"msr CONTROL, r2");
		break;
	}
}

int taskAFun(int a, int b, int c){
	return a + b + c;
}

int taskBFun(int a, int b, int c, int d){
	return a + b + c + d;
}

//void SVC_Handler(){
//	switchAccessLevel(privilege);
//}


void mainOS(){
	// Specify Stack Size for the MSP
	_S_MSP = &_estack ;
	_E_MSP = _S_MSP - 512;

	// Specify Stack Size for TASK A.
	_S_PSP_TaskA = _E_MSP - 8;	// margin for safty
	_E_PSP_TaskA = _S_PSP_TaskA - TASKA_SIZE;

	// Specify Stack Size for TASK B.
	_S_PSP_TaskB = _E_PSP_TaskA - 8;	// margin for safty
	_E_PSP_TaskB = _S_PSP_TaskB - TASKB_SIZE;

	while(1){
		// Task A Stack Implementation.
		if(taskAFlag == 1){
			// Set PSP to task A Stack Address.
			SET_SP_TO_PSP(_S_PSP_TaskA);
			// Switch From MSP to PSP.
			SWTICH_MSP_TO_PSP();
			// Switch Access level to user level (unprivliged)
			switchAccessLevel(unprivilege);
			// call TaskA
			taskAFlag = taskAFun(1, 2, 3);
			// Switch Access level to privlige.
			OS_Generate_Exception();
			// Switch From PSP to MSP;
			SWTICH_PSP_TO_MSP();
		}else if(taskBFlag == 1){
			// Set PSP to task A Stack Address.
			SET_SP_TO_PSP(_S_PSP_TaskB);
			// Switch From MSP to PSP.
			SWTICH_MSP_TO_PSP();
			// Switch Access level to user level (unprivliged)
			switchAccessLevel(unprivilege);
			// call TaskA
			taskBFlag = taskBFun(1, 2, 3, 4);
			// Switch Access level to privlige.
			OS_Generate_Exception();
			// Switch From PSP to MSP;
			SWTICH_PSP_TO_MSP();

	}
}
}



int OS_SVC_SET(int a, int b, int svcNum){
	int result = 0;
	switch(svcNum){
	case 1:
		__asm("svc #0x01");
		break;
	case 2:
		__asm("svc #0x02");
		break;
	case 3:
		__asm("svc #0x03");
		break;
	case 4:
		__asm("svc #0x04");
		break;
	}

	__asm("mov %0, r0": "=r" (result));
	return result;
}

__attribute__((naked))void SVC_Handler(){
	__asm("tst lr, #4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0, MSP \n\t"
			"mrsne r0, PSP \n\t"
			"B SVC_Services_Handler");
}

void PendSV_Handler(){
	//PendSV Setted.
}

// This function is called from assembly and the first argument in it the address of r0 register.
void SVC_Services_Handler(int* stackFramePointer){
	int svcNum;
	unsigned int param1, param2;
	param1 = stackFramePointer[0];
	param2 = stackFramePointer[1];
	svcNum = *((unsigned char*)(((unsigned char*)stackFramePointer[6]) - 2));
	switch(svcNum){
	case 1:
		stackFramePointer[0] = param1 + param2;
		break;
	case 2:
		stackFramePointer[0] = param1 - param2;
		break;
	case 3:
		stackFramePointer[0] = param1 * param2;
		break;
	case 4:
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
		break;
	}
}

void clockInit(void) {
	RCC_APB2ENR |= (1 << 2);
	// Enabling Clock For AFIO Register
	RCC_APB2ENR |= (1 << 0);
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
	// EXTI0 configuration to PORTA0
	AFIO_EXTICR1 = 0;
	// Mask Line 0
	EXTI_IMR |= (1<<0);
	// Rising Trigger Enabled For Line 0
	EXTI_RTSR |= (1<<0);
	// Enable NVIC Irq6(from Interrupt Vector Table)   <<>> EXTI0
	NVIC_EXTIE0 |= (1 << 6);

	// SVC Exception Lab
	volatile int result = 0;
	result = OS_SVC_SET(5, 5, 1); // Add Service.
	result = OS_SVC_SET(5, 5, 2); // Subtraction Service.
	result = OS_SVC_SET(5, 5, 3); // Multiplication service.
	result = OS_SVC_SET(0, 0, 4); // PendSV Service.

	while(1);
}

void EXTI0_IRQHandler() {

	if(irqFlag == 1){
		taskAFlag = 1;
		irqFlag = 0;
	}else{
		taskBFlag = 1;
		irqFlag = 1;
	}

	// Stop the interrupt request.
	EXTI_PR |= (1 << 0);
}
