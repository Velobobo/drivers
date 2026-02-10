#include "exti.h"

// user btn pc13

void pc13_exti_init(void){
	__disable_irq(); //disable global interrupts
	RCC->AHB1ENR|=1<<2; // clock access for gpio c
	// pc13 input pin as default , no need to set moder
	RCC->APB2ENR|=1<<14; // clock access for SYSCFG
	// select port C for exti13
	SYSCFG->EXTICR[3]|=1<<5;
	EXTI->IMR|=1<<13; // unmask exti13

	// select trigger type
	EXTI->FTSR|=1<<13;
	EXTI->RTSR|=1<<13;
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq(); //enable global interrupts
}
