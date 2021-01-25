#include "key.h"


void key_init(void)
{
  GPIO_InitTypeDef GPIO_KeyInit = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pins : PA15*/
  GPIO_KeyInit.Pin = GPIO_PIN_15;
  GPIO_KeyInit.Mode = GPIO_MODE_INPUT;
  GPIO_KeyInit.Pull = GPIO_PULLUP;
  GPIO_KeyInit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_KeyInit);

  /*Configure GPIO pins : PC10 PC11*/
  GPIO_KeyInit.Pin = GPIO_PIN_10| GPIO_PIN_11;
  GPIO_KeyInit.Mode = GPIO_MODE_INPUT;
  GPIO_KeyInit.Pull = GPIO_PULLUP;
  GPIO_KeyInit.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_KeyInit);
}


uint8_t scan_key(void)
{
	static uint8_t key =0;
	static uint32_t lasttime=0;

	if(!key)
	{
		if(K_1 == LOW || K_2 == LOW ||  K_3 == LOW)
		{
			//Delay 10ms chong nhieu
			if(!lasttime)	lasttime = HAL_GetTick();

			if(HAL_GetTick() - lasttime > 10)
			{
				key =1;

				if(K_1 == LOW)
				{
					return KEY1;
				}
				else if (K_2 == LOW)
				{
					return KEY2;
				}
				else if (K_3 == LOW)
				{
					return KEY3;
				}
			}
		}
	}
	else
	{
		if(K_1 == HIGH && K_2 == HIGH &&  K_3 == HIGH)	key = 0;
	}

	return 0;
}

