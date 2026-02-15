/*
 * bmm150.h
 *
 *  Created on: Jan 16, 2026
 *      Author: parth
 */

#ifndef BMM150_H_
#define BMM150_H_
void BMM150_byteRead(char reg,char* data);
void BMM150_burstRead(char reg,int n,char* data);
void BMM150_burstWrite(char reg,int n,char* data);
void BMM150_byteWrite(char reg,uint8_t data);
void BMM150_init(void);
void BMM150_readSensorData(int length,char *buffer);
#endif /* BMM150_H_ */
