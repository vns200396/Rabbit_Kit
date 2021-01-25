#ifndef _INFRARED_REFLECTIVE_H
#define _INFRARED_REFLECTIVE_H

#include "system.h"

#define INFRARED_REFLECTIVE 					PBin(1)

#define INFRARED_REFLECTIVE_CLK_ENABLE() 		__HAL_RCC_GPIOB_CLK_ENABLE();
#define INFRARED_REFLECTIVE_PIN 				GPIO_PIN_1
#define INFRARED_REFLECTIVE_PORT 				GPIOB

#define IN_REF_IRQn  	EXTI1_IRQn

void infrared_reflective_init(void);
void infrared_reflective_callback(void);
#endif
