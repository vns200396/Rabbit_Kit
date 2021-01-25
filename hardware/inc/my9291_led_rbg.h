#ifndef _MY9291_LED_RBG_H
#define _MY9291_LED_RBG_H

#include "system.h"
#include "stdbool.h"

typedef enum
{
        MY9291_CMD_ONE_SHOT_DISABLE = 0X00,
        MY9291_CMD_ONE_SHOT_ENFORCE = 0X01,
}MY9291_CMD_ONE_SHOT_TypDef;

typedef enum
{
        MY9291_CMD_REACTION_FAST = 0X00,
        MY9291_CMD_REACTION_SLOW = 0X01,
}MY9291_CMD_REACTION_TypDef;


typedef enum
{
        MY9291_CMD_BIT_WIDTH_16 = 0X00,
        MY9291_CMD_BIT_WIDTH_14 = 0X01,
        MY9291_CMD_BIT_WIDTH_12 = 0X02,
        MY9291_CMD_BIT_WIDTH_8 = 0X03,
}MY9291_CMD_BIT_WIDTH_TypDef;

typedef enum
{
        MY9291_CMD_FREQUENCY_DIVIDE_1 = 0X00,
        MY9291_CMD_FREQUENCY_DIVIDE_4 = 0X01,
        MY9291_CMD_FREQUENCY_DIVIDE_16 = 0X02,
        MY9291_CMD_FREQUENCY_DIVIDE_64 = 0X03,
} MY9291_CMD_FREQUENCY_TypDef;

typedef enum
{
        MY9291_CMD_SCATTER_APDM = 0X00,
        MY9291_CMD_SCATTER_PWM = 0X01,
} MY9291_CMD_SCATTER_TypDef;


typedef struct {
	MY9291_CMD_SCATTER_TypDef scatter:1;
	MY9291_CMD_FREQUENCY_TypDef frequency:2;
	MY9291_CMD_BIT_WIDTH_TypDef bit_width:2;
	MY9291_CMD_REACTION_TypDef reaction:1;
	MY9291_CMD_ONE_SHOT_TypDef one_shot:1;
        unsigned char resv:1;
} __attribute__ ((aligned(1), packed)) MY9291_CMD_TypDef;

typedef struct
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
    unsigned int warm;
} MY9291_COLOR_TypDef;

#define DI			PBout(9)
#define DCKI		PBout(8)

#define DI_PIN						GPIO_PIN_9
#define DI_PORT						GPIOB
#define DI_CLK_ENABLE()				__HAL_RCC_GPIOB_CLK_ENABLE();

#define DCKI_PIN					GPIO_PIN_8
#define DCKI_PORT					GPIOB
#define DCKI_CLK_ENABLE()			__HAL_RCC_GPIOB_CLK_ENABLE();


void setColor(MY9291_COLOR_TypDef color);
bool getState(void);
void setState(bool state);
void my9291_led_rbg_init(unsigned char channels);
void rainbow(unsigned char index);
void test_rbg(void);
#endif
