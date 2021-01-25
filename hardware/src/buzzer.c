#include "buzzer.h"

/**
  * @brief Buzzer Initialization Function
  * @param None
  * @retval None
  */
void buzzer_init(void)
{
  GPIO_InitTypeDef GPIO_BuzzerTypDef = {0};

  /* GPIO Ports Clock Enable */
  BUZZER_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC59 */
  GPIO_BuzzerTypDef.Pin = BUZZER_PIN;
  GPIO_BuzzerTypDef.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_BuzzerTypDef.Pull = GPIO_NOPULL;
  GPIO_BuzzerTypDef.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUZZER_PORT, &GPIO_BuzzerTypDef);
}


void test_buzzer(void)
{
	BUZZER =1;
	HAL_Delay(10);
	BUZZER =0;
	HAL_Delay(1000);
}
