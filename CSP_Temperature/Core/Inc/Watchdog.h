/*
 * Watchdog.h
 *
 *  Created on: Sep 10, 2020
 *      Author: David Bombardier
 */

#ifndef INC_WATCHDOG_H_
#define INC_WATCHDOG_H_

#include "main.h"

void MX_IWDG_Init(void);
IWDG_HandleTypeDef hiwdg;
#endif /* INC_WATCHDOG_H_ */
