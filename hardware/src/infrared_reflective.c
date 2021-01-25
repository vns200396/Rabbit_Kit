#include "infrared_reflective.h"
#include "bsp_debug_usart.h"

//#define EXTI_INFRARED_REFLECTIVE


void infrared_reflective_init(void)
{
	  GPIO_InitTypeDef   IR_TypDef;

	  /* Enable GPIOA clock */
	  INFRARED_REFLECTIVE_CLK_ENABLE();

#ifdef EXTI_INFRARED_REFLECTIVE
	  /* Configure PA.00 pin as input floating */
	  IR_TypDef.Mode = GPIO_MODE_IT_RISING;
	  IR_TypDef.Pull = GPIO_NOPULL;
	  IR_TypDef.Pin = INFRARED_REFLECTIVE_PIN;
	  HAL_GPIO_Init(INFRARED_REFLECTIVE_PORT, &IR_TypDef);

	  /* Enable and set EXTI line x Interrupt to the lowest priority */
	  HAL_NVIC_SetPriority(IN_REF_IRQn, 2, 0);
	  HAL_NVIC_EnableIRQ(IN_REF_IRQn);
#else
	  /*Configure GPIO pins : PA15*/
	  IR_TypDef.Pin = INFRARED_REFLECTIVE_PIN;
	  IR_TypDef.Mode = GPIO_MODE_INPUT;
	  IR_TypDef.Pull = GPIO_NOPULL;
	  IR_TypDef.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(INFRARED_REFLECTIVE_PORT, &IR_TypDef);

#endif
}


void infrared_reflective_callback(void)
{
	static uint8_t state =0;
#ifdef EXTI_INFRARED_REFLECTIVE
	  printf("Infrared Reflective \r\n");
#else
	 if(!INFRARED_REFLECTIVE)
	 {
		 if(!state)
		 {
			 state =1;
			 printf("Infrared Reflective \r\n");
		 }

	 }
	 else
	 {
		 state =0;
	 }

#endif

}


