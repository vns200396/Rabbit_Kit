#include "led.h"


/**
  * @brief Led Initialization Function
  * @param None
  * @retval None
  */
void led_init(void)
{
  GPIO_InitTypeDef GPIO_LedInit = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC7 PC8 PC9 */
  GPIO_LedInit.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_LedInit.Pull = GPIO_NOPULL;
  GPIO_LedInit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_LedInit);

  /*Configure GPIO pin : PA8 */
  GPIO_LedInit.Pin = GPIO_PIN_8;
  GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_LedInit.Pull = GPIO_NOPULL;
  GPIO_LedInit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_LedInit);
}
