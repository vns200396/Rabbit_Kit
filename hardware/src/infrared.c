#include "infrared.h"
#include "bsp_debug_usart.h"

//#define EXTI_INFRARED

void infrared_init(void)
{
	  GPIO_InitTypeDef   IR_TypDef;

	  /* Enable GPIOA clock */
	  INFRARED_CLK_ENABLE();

#ifdef EXTI_INFRARED
	  /* Configure PA.00 pin as input floating */
	  IR_TypDef.Mode = GPIO_MODE_IT_RISING;
	  IR_TypDef.Pull = GPIO_NOPULL;
	  IR_TypDef.Pin = INFRARED_PIN;
	  HAL_GPIO_Init(INFRARED_PORT, &IR_TypDef);

	  /* Enable and set EXTI line x Interrupt to the lowest priority */
	  HAL_NVIC_SetPriority(IR_IRQn, 2, 1);
	  HAL_NVIC_EnableIRQ(IR_IRQn);
#else
	  /*Configure GPIO pins : PA15*/
	  IR_TypDef.Pin = INFRARED_PIN;
	  IR_TypDef.Mode = GPIO_MODE_INPUT;
	  IR_TypDef.Pull = GPIO_NOPULL;
	  IR_TypDef.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(INFRARED_PORT, &IR_TypDef);

#endif
}


void infrared_callback(void)
{
	static uint8_t state =0;
#ifdef EXTI_INFRARED
	  printf("Infrared \r\n");
#else
	 if(!INFRARED)
	 {
		 if(!state)
		 {
			 state =1;
			 printf("Infrared \r\n");
		 }

	 }
	 else
	 {
		 state =0;
	 }

#endif

}


