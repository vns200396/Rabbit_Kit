#include "timer_base.h"


TIM_HandleTypeDef    TimHandle;


static __IO uint32_t timer=0;

void timer_base_init(void)
{
  /* Compute the prescaler value to have TIMx counter clock equal to 10000 Hz */
  /* Set TIMx instance */
  TimHandle.Instance = TIMx;

  /* Initialize TIMx peripheral as follows:
       + Period = 10000 - 1
       + Prescaler = (SystemCoreClock/10000) - 1
       + ClockDivision = 0
       + Counter direction = Up
  */
  TimHandle.Init.Period            = 10000 - 1;
  TimHandle.Init.Prescaler         = 72 - 1;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
  TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

  /* TIMx Peripheral clock enable */
  TIMx_CLK_ENABLE();
  /* Set the TIMx priority */
  HAL_NVIC_SetPriority(TIMx_IRQn, 3, 0);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIMx_IRQn);

  if (HAL_TIM_Base_Init(&TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /*##-2- Start the TIM Base generation in interrupt mode ####################*/
  /* Start Channel1 */
  if (HAL_TIM_Base_Start_IT(&TimHandle) != HAL_OK)
  {
    /* Starting Error */
    Error_Handler();
  }
}

void TIMx_IRQHandler(void)
{
	  /* TIM Update event */
	  if (__HAL_TIM_GET_FLAG(&TimHandle, TIM_FLAG_UPDATE) != RESET)
	  {
	    if (__HAL_TIM_GET_IT_SOURCE(&TimHandle, TIM_IT_UPDATE) != RESET)
	    {
	      __HAL_TIM_CLEAR_IT(&TimHandle, TIM_IT_UPDATE);

	    	  timer++;
	          HAL_TIM_PeriodElapsedCallback(&TimHandle);
	    }
	  }
}

