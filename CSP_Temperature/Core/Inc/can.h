/*
 * can.h
 *
 *  Created on: May 12, 2020
 *      Author: DBombardier
 */
#ifndef INC_CAN_H_
#define INC_CAN_H_
#include "stm32f1xx_hal.h"
CAN_HandleTypeDef 				hcan;
CAN_TxHeaderTypeDef        TxMessage;
CAN_RxHeaderTypeDef        RxMessage;

void MX_CAN_Init(void);
void canTransmit(uint16_t CanId, uint8_t lenght, uint8_t* CanMessage);
void canReceive(void);
#endif /* INC_CAN_H_ */
