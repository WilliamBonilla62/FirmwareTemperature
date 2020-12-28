/*
 * MuxControl.c
 *
 *  Created on: April 29, 2020
 *      Author: WBonilla & David Bombardier
 */
#include "Gpio.h"
#include "MCUMap.h"
#include "MuxControl.h"

GPIO_InitTypeDef GPIO_InitStruct = {0};

void MUXCONTROL1(uint8_t pinValue)
{
	uint8_t pinValueT;
	// This function Translate the desire value from the user to the hardware one.
	pinValueT=TransSoft2HardMux1(pinValue);
	// This function controls the U3 PTC MUX
	if(pinValueT&1)
		HAL_GPIO_WritePin(GPIOC,CMDPTC0_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC,CMDPTC0_Pin,GPIO_PIN_RESET);

	if((pinValueT>>1)&1)
		HAL_GPIO_WritePin(GPIOC,CMDPTC1_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC,CMDPTC1_Pin,GPIO_PIN_RESET);

	if((pinValueT>>2)&1)
		HAL_GPIO_WritePin(GPIOC,CMDPTC2_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC,CMDPTC2_Pin,GPIO_PIN_RESET);

	if((pinValueT>>3)&1)
		HAL_GPIO_WritePin(GPIOC,CMDPTC3_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC,CMDPTC3_Pin,GPIO_PIN_RESET);
}
void MUXCONTROL2(uint8_t pinValue)
{
	uint8_t pinValueT;
	pinValueT=TransSoft2HardMux2(pinValue);
	// This function controls the U4 Column MUX
	if(pinValueT&1)
		HAL_GPIO_WritePin(GPIOB,CMDC0_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOB,CMDC0_Pin,GPIO_PIN_RESET);

	if((pinValueT>>1)&1)
		HAL_GPIO_WritePin(GPIOB,CMDC1_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOB,CMDC1_Pin,GPIO_PIN_RESET);

	if((pinValueT>>2)&1)
		HAL_GPIO_WritePin(GPIOB,CMDC2_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOB,CMDC2_Pin,GPIO_PIN_RESET);

	if((pinValueT>>3)&1)
		HAL_GPIO_WritePin(GPIOB,CMDC3_Pin,GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOB,CMDC3_Pin,GPIO_PIN_RESET);
	}
void StrobeHigh()
{
	HAL_GPIO_WritePin(GPIOA,Strobe_Pin,GPIO_PIN_SET);
}
void StrobeLow()
{
	HAL_GPIO_WritePin(GPIOA,Strobe_Pin,GPIO_PIN_RESET);
}
void DECCONTROL(uint8_t pinValue)
{
	uint8_t pinValueT;
	pinValueT=TransSoft2HardDec(pinValue);
		if(pinValueT&1)
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC0_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC0_Pin,GPIO_PIN_RESET);
		}
		if((pinValueT>>1)&1)
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC1_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC1_Pin,GPIO_PIN_RESET);
		}
		if((pinValueT>>2)&1)
		{
			HAL_GPIO_WritePin(GPIOC,CMDDEC2_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC,CMDDEC2_Pin,GPIO_PIN_RESET);
		}
		if((pinValueT>>3)&1)
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC3_Pin,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOA,CMDDEC3_Pin,GPIO_PIN_RESET);
		}
//	HAL_Delay(100);
	StrobeHigh();
//	HAL_Delay(100);
	StrobeLow();
}
uint8_t TransSoft2HardMux1(uint8_t pinValue)
{
	if(pinValue==0)
	{
		return 5;
	}
	if(pinValue==1)
	{
		return 4;
	}
	if(pinValue==2)
	{
		return 3;
	}
	if(pinValue==3)
	{
		return 2;
	}
	if(pinValue==4)
	{
		return 1;
	}
	if(pinValue==5)
	{
		return 0;
	}
	if(pinValue==6)
	{
		return 15;
	}
	if(pinValue==7)
	{
		return 14;
	}
	if(pinValue==8)
	{
		return 13;
	}
	if(pinValue==9)
	{
		return 12;
	}
	if(pinValue==10)
	{
		return 11;
	}
	if(pinValue==11)
	{
		return 10;
	}
	return 16;
}
uint8_t TransSoft2HardMux2(uint8_t pinValue)
{
	if(pinValue==0)
		{
			return 5;
		}
		if(pinValue==1)
		{
			return 4;
		}
		if(pinValue==2)
		{
			return 3;
		}
		if(pinValue==3)
		{
			return 2;
		}
		if(pinValue==4)
		{
			return 1;
		}
		if(pinValue==5)
		{
			return 0;
		}
		if(pinValue==6)
		{
			return 15;
		}
		if(pinValue==7)
		{
			return 14;
		}
		if(pinValue==8)
		{
			return 13;
		}
		if(pinValue==9)
		{
			return 12;
		}
		if(pinValue==10)
		{
			return 11;
		}
		if(pinValue==11)
		{
			return 10;
		}
	return 16;
}
uint8_t TransSoft2HardDec(uint8_t pinValue)
{
	if(pinValue==0)
	{
		return 5;
	}
	if(pinValue==1)
	{
		return 4;
	}
	if(pinValue==2)
	{
		return 3;
	}
	if(pinValue==3)
	{
		return 1;
	}
	if(pinValue==4)
	{
		return 2;
	}
	if(pinValue==5)
	{
		return 0;
	}
	if(pinValue==6)
	{
		return 13;
	}
	if(pinValue==7)
	{
		return 12;
	}
	if(pinValue==8)
	{
		return 15;
	}
	if(pinValue==9)
	{
		return 14;
	}
	if(pinValue==10)
	{
		return 9;
	}
return 16;
}
void MX_Mux_init(void)
{
	//Puts the mux on an initial state
	StrobeLow();
	HAL_Delay(300);
	MUXCONTROL1(0);
	MUXCONTROL2(0);
	DECCONTROL(0);

	//Set the PB11 to high
	Set_Vref_High();
}

void Set_Vref_High()
{
	HAL_GPIO_WritePin(GPIOB,VREFMUX0,GPIO_PIN_SET);
}
