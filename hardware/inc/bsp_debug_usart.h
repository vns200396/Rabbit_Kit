#ifndef _BSP_DEBUG_USART_H
#define _BSP_DEBUG_USART_H

#include "system.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* User can use this section to tailor USARTx/UARTx instance used and associated
   resources */
/* Definition for USARTx clock resources */
#define BSP_DEBUG_USARTx                           USART1
#define BSP_DEBUG_USARTx_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE();
#define BSP_DEBUG_USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define BSP_DEBUG_USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()

#define BSP_DEBUG_USARTx_FORCE_RESET()             __HAL_RCC_USART1_FORCE_RESET()
#define BSP_DEBUG_USARTx_RELEASE_RESET()           __HAL_RCC_USART1_RELEASE_RESET()

/* Definition for USARTx Pins */
#define BSP_DEBUG_USARTx_TX_PIN                    GPIO_PIN_9
#define BSP_DEBUG_USARTx_TX_GPIO_PORT              GPIOA
#define BSP_DEBUG_USARTx_RX_PIN                    GPIO_PIN_10
#define BSP_DEBUG_USARTx_RX_GPIO_PORT              GPIOA

/* Define the STM32F10x hardware depending on the used BOARD SUPPORT */
#define  BSP_DEBUG_RTS_PORT                 		GPIOA
#define  BSP_DEBUG_CTS_PORT                 		GPIOA
#define  BSP_DEBUG_RTS_CLK_ENABLE()     			__HAL_RCC_GPIOA_CLK_ENABLE()
#define  BSP_DEBUG_CTS_CLK_ENABLE()     			__HAL_RCC_GPIOA_CLK_ENABLE()
#define  BSP_DEBUG_GPIO_RTSPin              		GPIO_PIN_12
#define  BSP_DEBUG_GPIO_CTSPin              		GPIO_PIN_11

void debug_config(uint32_t bau, uint32_t stopbits, uint32_t parity, uint32_t hwctrl);
#endif
