/*
 * can.c
 *
 *  Created on: May 12, 2020
 *      Author: David Bombardier
 */
#include "can.h"

/* CAN init function */
void MX_CAN_Init(void)
{
  CAN_FilterTypeDef  sFilterConfig;

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 4;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_11TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_4TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
  //  Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  sFilterConfig.FilterIdHigh = 0x700<<5;// a verifier le range des adresses qu<on veut qu'il applique
  sFilterConfig.FilterIdLow = 0;
  sFilterConfig.FilterMaskIdHigh = 0xfff<<5;
  sFilterConfig.FilterMaskIdLow = 0;
  sFilterConfig.FilterFIFOAssignment = 0;
  sFilterConfig.FilterActivation = ENABLE;
  sFilterConfig.FilterBank = 0;


  if (HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
	  {
		//Error_Handler();// Aucun error handler de fait encore
	  }


  if ( HAL_CAN_Start(&hcan) != HAL_OK)
   	  {
	   // Error_Handler();// Aucun error handler de fait encore
	  }

}

void canTransmit(uint16_t canId, uint8_t len, uint8_t* canMessage){
	TxMessage.StdId = canId;
	TxMessage.DLC = len;
	TxMessage.RTR = CAN_RTR_DATA;
	TxMessage.IDE = CAN_ID_STD;
	TxMessage.ExtId = 0x01;
	TxMessage.TransmitGlobalTime = DISABLE;
	uint8_t Data[8];
	uint32_t Tx_Mailbox=0;

  for(uint8_t i=0; i<len; i++) {
	  Data[i] = *canMessage;
    canMessage++;
  }

  if(HAL_CAN_GetTxMailboxesFreeLevel(&hcan)>0)
	  {
	  if (HAL_CAN_AddTxMessage(&hcan,&TxMessage,Data,&Tx_Mailbox) != HAL_OK)
		  {
		//	Error_Handler();// Aucun error handler de fait encore
		  }
	  }

}

void canReceive(void) {

	uint8_t Data0[8];
	uint8_t Data1[8];
	if (HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_RX_FIFO0)>0)
		  if (HAL_CAN_GetRxMessage(&hcan,CAN_RX_FIFO0,&RxMessage,Data0) != HAL_OK)
		   	  {
			    //Error_Handler();// Aucun error handler de fait encore
			  }

	if (HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_RX_FIFO1)>0)
		  if (HAL_CAN_GetRxMessage(&hcan,CAN_RX_FIFO1,&RxMessage,Data1) != HAL_OK)
		   	  {
			 //   Error_Handler();// Aucun error handler de fait encore
			  }
}








