#ifndef _ADC_LIGHT_H
#define _ADC_LIGHT_H

#include "system.h"

#define ADCx                            ADC1
#define ADCx_CLK_ENABLE()               __HAL_RCC_ADC1_CLK_ENABLE()

#define ADCx_FORCE_RESET()              __HAL_RCC_ADC1_FORCE_RESET()
#define ADCx_RELEASE_RESET()            __HAL_RCC_ADC1_RELEASE_RESET()

/* Definition of ADCx channels */
#define ADCx_CHANNEL                  	 ADC_CHANNEL_10

/* Definition of ADCx channels pins */
#define ADCx_CHANNEL_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define ADCx_CHANNEL_GPIO_PORT         GPIOC
#define ADCx_CHANNEL_PIN               GPIO_PIN_0

/* Definition of ADCx DMA resources */
#define ADCx_DMA_CLK_ENABLE()           __HAL_RCC_DMA1_CLK_ENABLE()
#define ADCx_DMA                        DMA1_Channel1

#define ADCx_DMA_IRQn                   DMA1_Channel1_IRQn
#define ADCx_DMA_IRQHandler             DMA1_Channel1_IRQHandler

/* Definition of ADCx NVIC resources */
#define ADCx_IRQn                       ADC1_2_IRQn
#define ADCx_IRQHandler                 ADC1_2_IRQHandler

void adc_init(void);
void get_value_adc_light(void);
#endif
