/*
 * Watchdog.c
 *
 *  Created on: Sep 10, 2020
 *      Author: David
 */
#include "Watchdog.h"
#include "stm32f1xx_hal.h"
void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN WWDG_Init 0 */

  /* USER CODE END WWDG_Init 0 */

  /* USER CODE BEGIN WWDG_Init 1 */

  /* USER CODE END WWDG_Init 1 */
	  hiwdg.Instance = IWDG;
	  hiwdg.Init.Prescaler = IWDG_PRESCALER_64;
	  hiwdg.Init.Reload = 624;
	  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
	  {
	 //   Error_Handler();
	  }
  /* USER CODE BEGIN WWDG_Init 2 */

  /* USER CODE END WWDG_Init 2 */

}

