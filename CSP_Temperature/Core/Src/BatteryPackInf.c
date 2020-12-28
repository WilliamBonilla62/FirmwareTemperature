/*
 * BatteryPackInf.c
 *
 *  Created on: 19 oct. 2020
 *      Author: bomd2001
 */
#include "BatteryPackInf.h"

#define NbColonne 		11
#define NbDecode		12
#define NbPTC			12
#define NbCells			144
#define DANGER		0X00U
#define WARNING		0x01U
#define NORMAL		0x02U
#define INIT		0x03U
#define LOSSTEMP	0x04U
#define WarningTemp		50
#define DangerTemp		58
#define CanAdressRange	0x300

//PTC CONVERSION CONSTANT
#define PTCCONSTANT1 			-10.063
#define PTCCONSTANT2 			55.389
#define PTCCONSTANT3 			-129.02
#define PTCCONSTANT4 			131.51

//#define PTCCONSTANT1 			0.000004458289271240750
//#define PTCCONSTANT2 			 -0.005607927867345
//#define PTCCONSTANT3 			8.724933010097933

typedef struct BatteryPack {
    uint8_t id;
	uint16_t Temperature[NbCells];
	uint8_t State;
	uint8_t MaxTemp;
	uint8_t SecondMaxTemp;
	uint8_t ThirdMaxTemp;
	uint8_t LowTemp;
	uint8_t MaxTempPtc;
	uint8_t AverageMatrixTemp;
	uint8_t AveragePtcTemp;
} BatteryPack;


BatteryPack batteryPack;

void BP_Initialisation(){

	for(uint8_t i=0;i<NbCells;i++)
	{
	    batteryPack.Temperature[i]=0;
	}

	batteryPack.id=1;
	batteryPack.State = INIT;
	batteryPack.MaxTemp=0;
	batteryPack.SecondMaxTemp=0;
	batteryPack.ThirdMaxTemp=0;
	batteryPack.LowTemp=100;
	batteryPack.MaxTempPtc=0;
	batteryPack.AverageMatrixTemp=0;
	batteryPack.AveragePtcTemp=0;
}

void BP_Reset(){
	batteryPack.State = INIT;
	batteryPack.MaxTemp=0;
	batteryPack.SecondMaxTemp=0;
	batteryPack.ThirdMaxTemp=0;
	batteryPack.LowTemp=100;
	batteryPack.MaxTempPtc=0;
	batteryPack.AverageMatrixTemp=0;
	batteryPack.AveragePtcTemp=0;
}

void BP_ReadMatrix()
{
	// Change the adc channel
	ChangeChannel(&hadc1,MATRIXCHANNEL);
	uint16_t SumTemp=0;
	for (uint8_t j=0;j<NbColonne;j++)
	{
		// Change the multiplexer to read every temp on the matrix
		MUXCONTROL2(j);
		for (uint8_t i=0;i<NbDecode;i++)
		{
			// Change the decoder to read every temp on the matrix
			DECCONTROL(i);

			//Read each temp on the matrix
			HAL_ADC_Start(&hadc1);
			if (HAL_ADC_PollForConversion(&hadc1,10)==HAL_OK)
					batteryPack.Temperature[i+(NbDecode*j)]=TempConvNTC(HAL_ADC_GetValue(&hadc1));

			//Sum of matrix temperature to make the average
			SumTemp=SumTemp+batteryPack.Temperature[i+(NbDecode*j)];

			//Check the state of each matrix temperature
			if (batteryPack.Temperature[i+(NbDecode*j)]>=DangerTemp)
				batteryPack.State = DANGER;
			else if(batteryPack.Temperature[i+(NbDecode*j)]>=WarningTemp && batteryPack.State != DANGER)
				batteryPack.State = WARNING;
			else if (batteryPack.State != DANGER || batteryPack.State != WARNING)
				batteryPack.State = NORMAL;

			//Check the third maximum temperature of matrix
			if (batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.SecondMaxTemp || batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.ThirdMaxTemp)
			{
				if(batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.SecondMaxTemp)
					batteryPack.ThirdMaxTemp=batteryPack.SecondMaxTemp;
				else
					batteryPack.ThirdMaxTemp=batteryPack.Temperature[i+(NbDecode*j)];
			}
			//Check the second maximum temperature of matrix
			if (batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.MaxTemp || batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.SecondMaxTemp)
			{
				if(batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.MaxTemp)
				batteryPack.SecondMaxTemp=batteryPack.MaxTemp;
				else
				batteryPack.SecondMaxTemp=batteryPack.Temperature[i+(NbDecode*j)];
			}
			//Check the maximum temperature of matrix
			if (batteryPack.Temperature[i+(NbDecode*j)]>batteryPack.MaxTemp)
				batteryPack.MaxTemp=batteryPack.Temperature[i+(NbDecode*j)];
			//Check the lowest temperature of the matrix
			if(batteryPack.Temperature[i+(NbDecode*j)]<batteryPack.LowTemp)
				batteryPack.LowTemp=batteryPack.Temperature[i+(NbDecode*j)];
		}
		//Average of temperature for the matrix
		batteryPack.AverageMatrixTemp=SumTemp/(NbCells-NbPTC);
	}
}
void BP_ReadPTC()
{
	uint16_t SumTemp=0;
	// Change the adc channel
	ChangeChannel(&hadc1,PTCCHANNEL);
	for (uint8_t i=0;i<NbPTC;i++)
	{
		// Change the multiplexer to read every ptc
		MUXCONTROL1(i);

		//Read each ptc
		HAL_ADC_Start(&hadc1);
			if ( HAL_ADC_PollForConversion(&hadc1,10)==HAL_OK)
				batteryPack.Temperature[(NbCells-NbPTC)+i]=TempConvPTC((HAL_ADC_GetValue(&hadc1)));

			//Sum of ptc temperature to make the average
			SumTemp=SumTemp+batteryPack.Temperature[(NbCells-NbPTC)+i];

			//Check the state of each ptc temperature
			if (batteryPack.Temperature[(NbCells-NbPTC)+i]>=DangerTemp)
				batteryPack.State = DANGER;
			else if(batteryPack.Temperature[(NbCells-NbPTC)+i]>=WarningTemp && batteryPack.State != DANGER)
				batteryPack.State = WARNING;
			else if (batteryPack.State != DANGER || batteryPack.State != WARNING)
				batteryPack.State = NORMAL;

			//Check the maximum temperature of ptc
			if (batteryPack.Temperature[(NbCells-NbPTC)+i]>batteryPack.MaxTempPtc)
			batteryPack.MaxTempPtc=batteryPack.Temperature[(NbCells-NbPTC)+i];

	}
	//Average of temperature for the ptc
	batteryPack.AveragePtcTemp=SumTemp/(NbPTC);
}
void BP_ReadAll()
{
	BP_ReadMatrix();
	BP_ReadPTC();
}

void BP_canFormat(){

	  uint16_t mask = CanAdressRange | batteryPack.id << 4;
	  uint8_t status[8];
			  status[0] = batteryPack.State;
			  status[1] = batteryPack.MaxTemp;
			  status[2] = batteryPack.SecondMaxTemp;
			  status[3] = batteryPack.ThirdMaxTemp;
			  status[4] = batteryPack.LowTemp;
			  status[5] = batteryPack.MaxTempPtc;
			  status[6] = batteryPack.AverageMatrixTemp;
			  status[7] = batteryPack.AveragePtcTemp;
			  canTransmit(mask, 8, status);
}

uint8_t TempConvNTC(uint32_t Voltage)
{
	uint32_t TemperatureNTC=0;
	float ScalingVoltage=(3.3/4096)*Voltage;
	float R1=10.0f;
	float R2=(ScalingVoltage*R1)/(3.3-ScalingVoltage);
	uint16_t B=3435;
	float T0=25+273.15;
	float Tampon=0;
	Tampon=(1/((logf(R2/R1)/B)+(1/T0)))-273.15;
	TemperatureNTC=(uint8_t)Tampon;
	return TemperatureNTC;
}

uint8_t TempConvPTC(uint32_t Voltage){
	float Voltage2=(Voltage*(3.3/4096));
	return (Voltage2*Voltage2*Voltage2*PTCCONSTANT1+Voltage2*Voltage2*PTCCONSTANT2 + Voltage2*PTCCONSTANT3+PTCCONSTANT4);
}

