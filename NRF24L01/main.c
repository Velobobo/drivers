#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"

#include "uart.h"
#include "exti.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "i2c.h"
#include "NRF24L01.h"
#include "spi.h"

int main(void)
{
	uint8_t buffer[32];
	uart2_rxtx_init();
	spi1_gpio_init();
	spi1_config();
	systickDelayMs_polling(100);
	NRF_init_receive();
	systickDelayMs_polling(10);


	while(1){
		NRF_Receive(buffer, 32);
		printf("%s \n\r",buffer);
		systickDelayMs_polling(10);
		memset(buffer,0,32);

	}


}


/*
void DMA1_Stream6_IRQHandler(void){
	if(DMA1->HISR & (1<<21)){ // check for transfer complete bit
		// clear interrupt flag
		DMA1->HIFCR |= 1<<21;
	}
}



void TIM2_IRQHandler(void){
	TIM2->SR &= ~(1<<0); // clear flag
	printf("A second passed...\n\r");
}


void SysTick_Handler(void){
	printf("A second passed...\n\r");
}


void ADC_IRQHandler(void){
	if(ADC1->SR & 1<<1){
		sensor_value=ADC1->DR;
		printf("Sensor value %d \n\r",(int)sensor_value);
	}
}

void USART2_IRQHandler(){
	if(USART2->SR & 1<<5){

	}

}
*/
