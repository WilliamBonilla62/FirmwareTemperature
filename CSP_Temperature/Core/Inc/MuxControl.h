/*
 * MuxControl.h
 *
 *  Created on: May 12, 2020
 *  Author: David Bombardier & William bonilla
 */
#ifndef INC_MUXCONTROL_H_
#define INC_MUXCONTROL_H_
#include "main.h"

void MUXCONTROL1(uint8_t pinValue);
void MUXCONTROL2(uint8_t pinValue);
void MUXCONTROL3(uint8_t pinValue);
void DECCONTROL(uint8_t pinValue);
uint8_t TransSoft2HardMux1(uint8_t pinValue);
uint8_t TransSoft2HardMux2(uint8_t pinValue);
uint8_t TransSoft2HardDec(uint8_t pinValue);
void MX_Mux_init();
void StrobeHigh();
void StrobeLow();
void Set_Vref_High();
#endif
