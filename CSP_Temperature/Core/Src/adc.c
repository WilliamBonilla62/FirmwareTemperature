#include "adc.h"




void MX_ADC_Init(void)
{
	  /* USER CODE BEGIN ADC_Init 0 */

	  /* USER CODE END ADC_Init 0 */
	ADC_ChannelConfTypeDef sConfig = {0};
	  /* USER CODE BEGIN ADC_Init  */

	  /* USER CODE END ADC_Init  */
	  /**
	   *
	  */
	  hadc1.Instance = ADC1;
	  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	  hadc1.Init.ContinuousConvMode = DISABLE;
	  hadc1.Init.DiscontinuousConvMode = DISABLE;
	  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hadc1.Init.NbrOfConversion = 1;
	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	   // Error_Handler();
	  }
	  /** Configure Regular Channel
	   *
	  */
	  sConfig.Channel = ADC_CHANNEL_15;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	   // Error_Handler();
	  }
	  /* USER CODE BEGIN ADC_Init  */

	  /* USER CODE END ADC_Init  */
}
void ChangeChannel(ADC_HandleTypeDef *hadc1,uint8_t Channel)
{
	if(Channel==PTCCHANNEL||Channel==MATRIXCHANNEL)
	{
	ADC_ChannelConfTypeDef sConfig = {0};
	if (Channel==0)
		  sConfig.Channel = ADC_CHANNEL_0;
	else
		  sConfig.Channel = ADC_CHANNEL_15;

	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
	  if (HAL_ADC_ConfigChannel(hadc1, &sConfig) != HAL_OK)
		  {
			//Error_Handler();
		  }
	}
	else
	{
		//Error_Handler(); //pas fait encore
	}

}
