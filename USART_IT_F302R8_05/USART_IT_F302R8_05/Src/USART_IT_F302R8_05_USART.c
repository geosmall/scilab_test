/*
 * File: USART_IT_F302R8_05_USART.c
 *
 * Generated by USART Coder for Xcos with scilab-5.5.2
 * C/C++ source code generated on  :09-Oct-2020
 *
 * Model version      :1.0
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */
#include "USART_IT_F302R8_05.h"
#include "USART_IT_F302R8_05_USART.h"
extern void** USART_IT_F302R8_05_block_outtbptr; //External array definition of output pointers for blocks 

/*
*******************************************************************************
USART Receive variables definition
*******************************************************************************
*/
struct USART_RxDataLinkTypeDef* G_Usart_RxData;
void*  G_Usart_RxHandler;
struct USART_RxDataLinkTypeDef USART2_RxDataLink;
uint8_t G_USART2_RxDataBuffer[USART2_RX_BUFF_SIZE];

/*
*******************************************************************************
Rx Transfer completed callbacks
Input: UART handle
*******************************************************************************
*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
   struct USART_RxDataLinkTypeDef*   pL_UART_RxData = G_Usart_RxData;
   UART_HandleTypeDef*     pL_UART_Handler = (UART_HandleTypeDef*)G_Usart_RxHandler;
   if(pL_UART_Handler == huart)
   {
      pL_UART_RxData->rxStatus = USART_RX_OK;
   }
}

/*
*******************************************************************************
Receive Initialization of USART2
*******************************************************************************
*/
void USART2_Rx_Initialization(void)
{
   G_Usart_RxData = &USART2_RxDataLink;
   G_Usart_RxHandler = (void*)&huart2;
   USART2_RxDataLink.ptRcv = G_USART2_RxDataBuffer;
   USART2_RxDataLink.rxStatus = USART_RX_OFF;
   /* Enable Software Interrupt request*/
   EXTI->IMR |= 1 << 13;
}

/*
*******************************************************************************
USART Send variables definition
*******************************************************************************
*/
struct USART_TxDataLinkTypeDef* G_Usart_TxData;
void*   G_Usart_TxHandler;
struct USART_TxDataLinkTypeDef USART2_TxDataLink;
uint8_t G_USART2_TxDataBuffer[32];

/*
*******************************************************************************
Tx Transfer completed callbacks
Input: UART handle
*******************************************************************************
*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
   struct USART_TxDataLinkTypeDef*  pL_UART_TxData = G_Usart_TxData;
  UART_HandleTypeDef*   pL_UART_Handler = (UART_HandleTypeDef*)G_Usart_TxHandler;
   if(pL_UART_Handler == huart)
  {
      pL_UART_TxData->txStatus = USART_TX_OK;
      pL_UART_TxData->pt_Tx_R +=  pL_UART_TxData->nbSent;
      if(pL_UART_TxData->pt_Tx_R >= pL_UART_TxData->pt_EndTx_Buff)
       {
           pL_UART_TxData->pt_Tx_R = pL_UART_TxData->pt_StartTx_Buff;
       }
       if(pL_UART_TxData->txLock == 0)
       {
           pL_UART_TxData->nb2Send -=  pL_UART_TxData->nbSent;
       }
       else
       {
           pL_UART_TxData->txLock = 2;
       }
   }
}
/*
*******************************************************************************
Transmit Initialization of USART2
*******************************************************************************
*/
void USART2_Tx_Initialization(void)
{
   G_Usart_TxData = &USART2_TxDataLink;
   G_Usart_TxHandler = (void*)&huart2;
   USART2_TxDataLink.nb2Send = 0;
   USART2_TxDataLink.nbSent = 0;
   USART2_TxDataLink.nbMsgLost = 0;
   USART2_TxDataLink.buffSize = 32;
   USART2_TxDataLink.pt_StartTx_Buff = G_USART2_TxDataBuffer;
   USART2_TxDataLink.pt_EndTx_Buff = &G_USART2_TxDataBuffer[32];
   USART2_TxDataLink.pt_Tx_W = G_USART2_TxDataBuffer;
   USART2_TxDataLink.pt_Tx_R = G_USART2_TxDataBuffer;
   USART2_TxDataLink.CopyDataFcn = USART2_CopyDataFcn;
   USART2_TxDataLink.SendDataFcn = USART2_SendDataFcn;
   USART2_TxDataLink.txStatus = USART_TX_OFF;
   USART2_TxDataLink.txLock = 0;
}


/*
*******************************************************************************
USART2_CopyDataFcn
Input: pointer to data to send , lengh(number) of data to send and
ring buffer info
*******************************************************************************
*/
void  USART2_CopyDataFcn(uint8_t* ptSrc, uint16_t DataLength, struct USART_TxDataLinkTypeDef* ptInfo)
{
   uint16_t L_sizeMsg;
   uint16_t L_idx;
   /* Copy msg to send to ring buffer */
   L_sizeMsg = 0;
   for(L_idx=0;L_idx<DataLength;L_idx++)
   {
       if((((uint32_t)ptInfo->pt_Tx_W == (uint32_t)ptInfo->pt_Tx_R)&&ptInfo->nb2Send!=0))
           break; //Ring Buffer is full.
       *(char*)ptInfo->pt_Tx_W++ = *(char*)ptSrc++;
       L_sizeMsg++;
       if(ptInfo->pt_Tx_W == ptInfo->pt_Tx_R)
           break; //Ring Buffer is full.
       if(ptInfo->pt_Tx_W == ptInfo->pt_EndTx_Buff)
       {
           //Revolve buffer
           ptInfo->pt_Tx_W = ptInfo->pt_StartTx_Buff;
       }
   }
   /* update nb of data to send */
   ptInfo->txLock = 1; //Access locked
   ptInfo->nb2Send += L_sizeMsg;
   if(ptInfo->txLock == 2) //If end of send interrupt mode arrived during last instruction
       ptInfo->nb2Send -=  ptInfo->nbSent;
   ptInfo->txLock = 0; //Unlock access
   if(L_sizeMsg < DataLength)
       ptInfo->nbMsgLost++; //Message not all sent
}

/*
*******************************************************************************
USART2_SendDataFcn
Input: ring buffer info
*******************************************************************************
*/
void  USART2_SendDataFcn(struct USART_TxDataLinkTypeDef* ptInfo)
{
   uint16_t L_sizeMsg;
   /* If USART is not already running and data to send */
   if(ptInfo->txStatus != USART_TX_ON && ptInfo->nb2Send)
   {
       ptInfo->txStatus = USART_TX_ON;
       L_sizeMsg = (uint32_t)ptInfo->pt_EndTx_Buff - (uint32_t)ptInfo->pt_Tx_R;
       /* Send all msg or end of ring buffer */
       if(ptInfo->nb2Send <= L_sizeMsg)
       {
           ptInfo->nbSent = ptInfo->nb2Send;
           /* USART2 interrupt send mode*/
           HAL_UART_Transmit_IT(&huart2, ptInfo->pt_Tx_R, ptInfo->nb2Send);
       }
       else
       {
           ptInfo->nbSent = L_sizeMsg;
           /* USART2 interrupt send mode*/
           HAL_UART_Transmit_IT(&huart2, ptInfo->pt_Tx_R, L_sizeMsg);
       }
   }
}


void USART_Initialize(void){
   USART_IT_F302R8_05_block_outtbptr[2] = (uint16_t*)&USART2_RxDataLink.nbRcv; //Set first output block pointer
   USART_IT_F302R8_05_block_outtbptr[3] = (uint8_t*)&USART2_RxDataLink.ptRcv; //Set second output block pointer
   USART2_Rx_Initialization(); //Initialize USART2 to receive
   USART_IT_F302R8_05_block_outtbptr[4] = (uint16_t*)&USART2_TxDataLink.nbSent; //Set output block pointer
   USART2_Tx_Initialization(); //Initialize USART2 to transmit
}

