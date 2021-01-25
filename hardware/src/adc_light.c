#include "adc_light.h"
#include "bsp_debug_usart.h"

/* ADC handler declaration */
ADC_HandleTypeDef    AdcHandle;

/**
  * @brief  ADC configuration
  * @param  None
  * @retval None
  */
void adc_init(void)
{
  GPIO_InitTypeDef          GPIO_InitStruct;
  ADC_ChannelConfTypeDef   sConfig;


  ADCx_FORCE_RESET();
  ADCx_RELEASE_RESET();

  ADCx_CLK_ENABLE();
  ADCx_CHANNEL_GPIO_CLK_ENABLE();


  /* Configuration of ADCx init structure: ADC parameters and regular group */
  AdcHandle.Instance = ADCx;

  AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
  AdcHandle.Init.ScanConvMode          = ADC_SCAN_DISABLE;              /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
  AdcHandle.Init.ContinuousConvMode    = DISABLE;                       /* Continuous mode disabled to have only 1 conversion at each conversion trig */
  AdcHandle.Init.NbrOfConversion       = 1;                             /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.DiscontinuousConvMode = DISABLE;                       /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.NbrOfDiscConversion   = 1;                             /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.ExternalTrigConv      = ADC_SOFTWARE_START;            /* Software start to trig the 1st conversion manually, without external event */

  HAL_ADC_Init(&AdcHandle);

  /* Configure GPIO pin of the selected ADC channel */
  GPIO_InitStruct.Pin = ADCx_CHANNEL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStruct);


  /* Configuration of channel on ADCx regular group on sequencer rank 1 */
  /* Note: Considering IT occurring after each ADC conversion if ADC          */
  /*       conversion is out of the analog watchdog window selected (ADC IT   */
  /*       enabled), select sampling time and ADC clock with sufficient       */
  /*       duration to not create an overhead situation in IRQHandler.        */
  sConfig.Channel      = ADCx_CHANNEL;
  sConfig.Rank         = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;

  if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig) != HAL_OK)
  {
    /* Channel Configuration Error */
    Error_Handler();
  }
}

void get_value_adc_light(void)
{
	uint16_t value =0;

	HAL_ADC_Start(&AdcHandle);
	HAL_ADC_PollForConversion(&AdcHandle, 100);

	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&AdcHandle), HAL_ADC_STATE_REG_EOC))
	{
		value = HAL_ADC_GetValue(&AdcHandle);
	}

	printf("ADC Light: %.4f \r\n", ((float)value*3.3)/4096);
}
