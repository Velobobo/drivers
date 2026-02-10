#include "adc.h"
#include "stm32f4xx.h"

void pa1_adc_init(void){
	__disable_irq();
	RCC->AHB1ENR|=1<<0; // clock access GPIO A
	GPIOA->MODER|=0b11<<2; // set mode of PA1 to analog

	RCC->APB2ENR|=1<<8; // clock access to adc module
	ADC1->CR1|=1<<24; // Resolution set to 10 bit
	//ADC1->SMPR2 for sampling rate
	// conversion sequence start
	ADC1->SQR3|=1<<0; //CH1 first
	// conversion sequence length
	ADC1->SQR1=0;

	// end of conversion interrupt enable
	ADC1->CR1|=1<<5;
	// enable adc module
	ADC1->CR2|=1<<0;
	NVIC_EnableIRQ(ADC_IRQn);
	__enable_irq();

}

void start_conversion(void){
	ADC1->CR2|=1<<1; // enable continuous conversion
	ADC1->CR2|=1<<30; // adc on
}

/*
uint32_t adc_read(void){
	while(!(ADC1->SR & 1<<1)); // check when conversion is complete;
	return ADC1->DR;
}
*/
