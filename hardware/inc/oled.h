#ifndef __OLED_H
#define __OLED_H

#include "system.h"

#define SCL_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE()
#define SCL_PIN				GPIO_PIN_6
#define SCL_PORT			GPIOB

#define SDA_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE()
#define SDA_PIN				GPIO_PIN_7
#define SDA_PORT			GPIOB

#define SCL		PBout(6)
#define SDA		PBout(7)

#define ADDR_OLED	(0x3C << 1)
#define WRITE_DATA	0x40
#define WRITE_CMD	0x00

#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64

void iic_init(void);
void iic_write_byte(uint8_t dat);
void oled_write_dat(uint8_t	dat);
void oled_init(void);
void oled_set_pos(uint8_t x, uint8_t y);
void oled_clscr(void);
void oled_display_on(void);
void oled_display_off(void);
void oled_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
void oled_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size);
void oled_DrawBMP(uint8_t x0, uint8_t y0,uint8_t x1, uint8_t y1,uint8_t *bmp);
#endif
