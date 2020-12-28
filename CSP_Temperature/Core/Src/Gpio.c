#include "Gpio.h"
#include "MCUMap.h"

void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	  /* GPIO Ports Clock Enable */
	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, Strobe_Pin|CMDDEC0_Pin|CMDDEC1_Pin|CMDDEC3_Pin|CMDDEC2_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOB, CMDC3_Pin|CMDC2_Pin|CMDC1_Pin|CMDC0_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOC, CMDPTC0_Pin|CMDPTC1_Pin|CMDPTC2_Pin|CMDPTC3_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pins : Strobe_Pin CMDDEC0_Pin CMDDEC1_Pin CMDDEC3_Pin CMDDEC2_Pin */
	  GPIO_InitStruct.Pin = Strobe_Pin|CMDDEC0_Pin|CMDDEC1_Pin|CMDDEC3_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  /*Configure GPIO pins : CMDC3_Pin CMDC2_Pin CMDC0_Pin CMDC1_Pin */
	  GPIO_InitStruct.Pin = CMDC3_Pin|CMDC2_Pin|CMDC0_Pin|CMDC1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  /*Configure GPIO pins : Strobe_Pin CMDPTC0_Pin CMDPTC1_Pin CMDPTC3_Pin CMDPTC2_Pin*/
	  GPIO_InitStruct.Pin = CMDPTC0_Pin|CMDPTC1_Pin|CMDPTC2_Pin|CMDPTC3_Pin|CMDDEC2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  /*Configure GPIO in: Vrefmux0 */
	  GPIO_InitStruct.Pin = VREFMUX0;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
