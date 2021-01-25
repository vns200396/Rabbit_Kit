#ifndef _TIMER_BASE_H
#define _TIMER_BASE_H

#include "system.h"


#define TIMx                           TIM3
#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()


/* Definition for TIMx's NVIC */
#define TIMx_IRQn                      TIM3_IRQn
#define TIMx_IRQHandler                TIM3_IRQHandler


void timer_base_init(void);
void Delay_us(uint32_t us);
#endif
