#ifndef _KEY_H
#define _KEY_H

#include "system.h"


#define KEY1	0x01
#define KEY2	0x02
#define KEY3	0x03

#define K_1		PAin(15)
#define K_2		PCin(10)
#define K_3		PCin(11)

void key_init(void);
uint8_t scan_key(void);
#endif
