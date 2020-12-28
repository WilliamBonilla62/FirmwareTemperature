/*
 * BatteryPackInf.h
 *
 *  Created on: 19 oct. 2020
 *      Author: bomd2001
 */

#ifndef INC_BATTERYPACKINF_H_
#define INC_BATTERYPACKINF_H_
#include "stm32f1xx_hal.h"
#include "adc.h"
#include "can.h"
#include "MuxControl.h"
#include <string.h>
#include <math.h>

void BP_Initialisation();
void BP_Reset();
void BP_ReadMatrix();
void BP_ReadPTC();
void BP_ReadAll();
void BP_canFormat();
uint8_t TempConvNTC(uint32_t Voltage);
uint8_t TempConvPTC(uint32_t Voltage);

#endif /* INC_BATTERYPACKINF_H_ */
