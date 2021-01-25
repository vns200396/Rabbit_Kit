#ifndef _LED_H
#define _LED_H

#include "system.h"


#define	LED1	PCout(7)
#define	LED2	PCout(8)
#define	LED3	PCout(9)
#define	LED4	PAout(8)

void led_init(void);
#endif
