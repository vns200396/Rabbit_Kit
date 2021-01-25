#ifndef _INFRARED_H
#define _INFRARED_H

#include "system.h"

#define INFRARED								PCin(4)

#define INFRARED_CLK_ENABLE() 					__HAL_RCC_GPIOC_CLK_ENABLE();
#define INFRARED_PIN 							GPIO_PIN_4
#define INFRARED_PORT 							GPIOC

#define IR_IRQn  								EXTI4_IRQn

void infrared_init(void);
void infrared_callback(void);
#endif
