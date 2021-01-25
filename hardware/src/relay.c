#include "relay.h"


void relay_init(void)
{
  GPIO_InitTypeDef GPIO_RelayInit = {0};

  /** DISABLE: JTAG-DP Disabled and SW-DP Disabled
  */
  __HAL_AFIO_REMAP_SWJ_NOJTAG();

  /* GPIO Ports Clock Enable */
  RELAY_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB3*/
  GPIO_RelayInit.Pin = RELAY_PIN;
  GPIO_RelayInit.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_RelayInit.Pull = GPIO_PULLDOWN;
  GPIO_RelayInit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(RELAY_PORT, &GPIO_RelayInit);
}
