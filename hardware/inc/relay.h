#ifndef _RELAY_H
#define _RELAY_H

#include "system.h"

#define	RELAY	PBout(3)

#define	RELAY_CLK_ENABLE()		  __HAL_RCC_GPIOB_CLK_ENABLE()
#define	RELAY_PIN		  		  GPIO_PIN_3
#define	RELAY_PORT		  		  GPIOB


void relay_init(void);
#endif
