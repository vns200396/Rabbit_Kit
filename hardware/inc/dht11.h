#ifndef _DHT11_H
#define _DHT11_H

#include "system.h"


#define DHT11_CLK_ENABLE() 			__HAL_RCC_GPIOB_CLK_ENABLE()
#define DHT11 						GPIO_PIN_0
#define GPIO_DHT11 					GPIOB

#define DHT11_DQ_IN PBin(0)
#define DHT11_DQ_OUT PBout(0)


void DHT11_IO_OUT(void);
void DHT11_IO_IN(void);
uint8_t DHT11_Init(void);
void DHT11_Rst(void);
uint8_t DHT11_Check(void);
uint8_t DHT11_Read_Bit(void);
uint8_t DHT11_Read_Byte(void);
uint8_t DHT11_Read_Data(uint8_t *temp,uint8_t *humi);
void dht11_test();
#endif
