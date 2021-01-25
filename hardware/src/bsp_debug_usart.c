#include "bsp_debug_usart.h"


/* UART handler declaration */
UART_HandleTypeDef DebugHandle;

void debug_config(uint32_t bau, uint32_t stopbits, uint32_t parity, uint32_t hwctrl)
{
	  GPIO_InitTypeDef  GPIO_DebugTypDef;


	  // Reset peripherals USART
	  BSP_DEBUG_USARTx_FORCE_RESET();
	  BSP_DEBUG_USARTx_RELEASE_RESET();

	  //Disable peripherals and GPIO Clocks
	  HAL_GPIO_DeInit(BSP_DEBUG_USARTx_TX_GPIO_PORT, BSP_DEBUG_USARTx_TX_PIN);
	  HAL_GPIO_DeInit(BSP_DEBUG_USARTx_RX_GPIO_PORT, BSP_DEBUG_USARTx_RX_PIN);


	  //Enable peripherals and GPIO Clocks
	  BSP_DEBUG_USARTx_RX_GPIO_CLK_ENABLE();
	  BSP_DEBUG_USARTx_TX_GPIO_CLK_ENABLE();
	  BSP_DEBUG_RTS_CLK_ENABLE();
	  BSP_DEBUG_CTS_CLK_ENABLE();

	  /* Enable USARTx clock */
	  BSP_DEBUG_USARTx_CLK_ENABLE();


	  // Configure peripheral GPIO
	  /* Debug TX GPIO pin configuration  */
	  GPIO_DebugTypDef.Pin       = BSP_DEBUG_USARTx_TX_PIN;
	  GPIO_DebugTypDef.Mode      = GPIO_MODE_AF_PP;
	  GPIO_DebugTypDef.Pull      = GPIO_PULLUP;
	  GPIO_DebugTypDef.Speed     = GPIO_SPEED_FREQ_HIGH;

	  HAL_GPIO_Init(BSP_DEBUG_USARTx_TX_GPIO_PORT, &GPIO_DebugTypDef);

	  /* Debug RX GPIO pin configuration  */
	  GPIO_DebugTypDef.Pin = BSP_DEBUG_USARTx_RX_PIN;

	  HAL_GPIO_Init(BSP_DEBUG_USARTx_RX_GPIO_PORT, &GPIO_DebugTypDef);

	  if(hwctrl == UART_HWCONTROL_RTS || hwctrl == UART_HWCONTROL_RTS_CTS)
	  {
		  /* Debug RTS GPIO pin configuration  */
		  GPIO_DebugTypDef.Pin       = BSP_DEBUG_GPIO_RTSPin;
		  GPIO_DebugTypDef.Mode      = GPIO_MODE_AF_PP;
		  GPIO_DebugTypDef.Pull      = GPIO_PULLUP;
		  GPIO_DebugTypDef.Speed     = GPIO_SPEED_FREQ_HIGH;

		  HAL_GPIO_Init(BSP_DEBUG_RTS_PORT, &GPIO_DebugTypDef);
	  }

	  if(hwctrl == UART_HWCONTROL_CTS || hwctrl == UART_HWCONTROL_RTS_CTS)
	  {
		  /* Debug RTS GPIO pin configuration  */
		  GPIO_DebugTypDef.Pin       = BSP_DEBUG_GPIO_RTSPin;
		  /* Debug CTS GPIO pin configuration  */
		  GPIO_DebugTypDef.Pin = BSP_DEBUG_GPIO_CTSPin;
		  GPIO_DebugTypDef.Mode      = GPIO_MODE_INPUT;
		  GPIO_DebugTypDef.Pull      = GPIO_PULLUP;
		  GPIO_DebugTypDef.Speed     = GPIO_SPEED_FREQ_HIGH;

		  HAL_GPIO_Init(BSP_DEBUG_CTS_PORT, &GPIO_DebugTypDef);
	  }


	  //Configure the UART peripheral
	  DebugHandle.Instance        = BSP_DEBUG_USARTx;

	  DebugHandle.Init.BaudRate   = bau;
	  DebugHandle.Init.WordLength = UART_WORDLENGTH_8B;
	  DebugHandle.Init.StopBits   = stopbits;
	  DebugHandle.Init.Parity     = parity;
	  DebugHandle.Init.HwFlowCtl  = hwctrl;
	  DebugHandle.Init.Mode       = UART_MODE_TX_RX;

	  if (HAL_UART_Init(&DebugHandle) != HAL_OK)
	  {
	    /* Initialization Error */
	    Error_Handler();
	  }
}
