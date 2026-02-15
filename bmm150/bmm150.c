#include <stdint.h>
#include "bmm150.h"
#include "i2c.h"
#include "uart.h"
#include <stdio.h>
#include "systick.h"

#define BMM150 0x10

void BMM150_byteRead(char reg,char* data){
	I2C1_byteRead(BMM150, reg, data);
}
void BMM150_burstRead(char reg,int n,char* data){
	I2C1_burstRead(BMM150, reg,n, data);
}
void BMM150_burstWrite(char reg,int n,char* data){
	I2C1_burstWrite(BMM150, reg, n, data);
}
void BMM150_byteWrite(char reg,uint8_t data){
	uint8_t temp=data;
	I2C1_burstWrite(BMM150, reg, 1, &temp);
}


void BMM150_init(void){
	uint8_t temp;
	// checking chipid
	BMM150_byteWrite(0x4B, 0x1); // turn on power
	systickDelayMs(10);
	BMM150_byteRead(0x40,&temp);
	if(temp==0x32){
		printf("CHIPID : Correct\n\r");
	}
	else{
		printf("CHIPID : 0x%02X \n\r",temp);
	}

	BMM150_byteWrite(0x4C, 0x0); // normal mode
	BMM150_byteWrite(0x4E, 0x84); // preset
}

void BMM150_readSensorData(int length,char *buffer){
	BMM150_burstRead(0x42, length, buffer);
}
