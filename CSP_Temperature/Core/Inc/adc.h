/*
 * adc.h
 *
 *  Created on: 09 Septembre, 2020
 *      Author: David Bombardier & William Bonilla
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32f1xx_hal.h"

#define MATRIXCHANNEL 	15
#define PTCCHANNEL		0

enum AnalogInput{

	AnalogMatrix = 0,
	AnalogPTC,

	NB_AnalogInput
};
ADC_HandleTypeDef hadc1;

void MX_ADC_Init(void);
void ChangeChannel(ADC_HandleTypeDef *hadc1,uint8_t Channel);

#endif /* INC_ADC_H_ */
