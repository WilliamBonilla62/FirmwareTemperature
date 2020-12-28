/*
 * FrameWork.h
 *
 *  Created on: 09 Septembre, 2020
 *      Author: David Bombardier & William Bonilla
 */

#ifndef INC_FRAMEWORK_H_
#define INC_FRAMEWORK_H_

#include "stm32f1xx_hal.h"
#include "Watchdog.h"

uint32_t FrameWorkTimeGet(void);
uint32_t FrameWorkTimeDiff(uint32_t Compare);
_Bool FrameWorkTimeIsDue(uint32_t Compare,uint32_t interval);
void FrameWorkTask(void);
void FrameWorkInit(void);

#endif /* INC_FRAMEWORK_H_ */
