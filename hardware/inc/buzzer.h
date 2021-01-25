#ifndef _BUZZER_H
#define _BUZZER_H

#include "system.h"

#define BUZZER	PCout(5)

#define BUZZER_PIN					GPIO_PIN_5
#define BUZZER_PORT					GPIOC
#define BUZZER_CLK_ENABLE()			__HAL_RCC_GPIOC_CLK_ENABLE();

void buzzer_init(void);
void test_buzzer(void);
#endif
