/*
 * bmi270.h
 *
 *  Created on: Jan 13, 2026
 *      Author: parth
 */

#ifndef BMI270_H_
#define BMI270_H_
#include <stdint.h>
extern const uint8_t bmi270_config_file[];
extern const uint16_t BMI270_CONFIG_FILE_LEN;
void BMI270_byteRead(char reg,char* data);
void BMI270_burstRead(char reg,int n,char* data);
void BMI270_burstWrite(char reg,int n,char* data);
void BMI270_byteWrite(char reg,uint8_t data);
void BMI270_init(void);
void BMI270_readSensorData(int length,char *buffer);

#endif /* BMI270_H_ */
