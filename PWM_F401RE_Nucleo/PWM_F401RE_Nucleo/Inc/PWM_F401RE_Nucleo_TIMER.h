/*
 * File: PWM_F401RE_Nucleo_TIMER.h
 *
 * Generated by TIMER_GP Coder for Xcos with scilab-5.5.2
 * C/C++ source code generated on  :12-Oct-2020
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

#include "STM32_Config.h"

extern void TIMER_Initialize(void); //TIMER initialize function


#ifndef PWM_F401RE_Nucleo_TIMER_h_
#define PWM_F401RE_Nucleo_TIMER_h_

/** 
* @brief  TIM data information
**/
typedef struct  {
uint32_t     TIM_Prescaler;
uint32_t     TIM_APBClock;
uint32_t     TIM_ARR;
uint32_t     TIM_Clock;
uint32_t     TIM_Freq;
uint8_t      CH1_type;
uint8_t      CH2_type;
uint8_t      CH3_type;
uint8_t      CH4_type;
int32_t      CH1_duty;
int32_t      CH2_duty;
int32_t      CH3_duty;
int32_t      CH4_duty;
/* Input Capture data */
uint32_t* ICCData;
uint32_t ICC1Capture;
uint32_t ICC1Freq;
uint32_t ICC1Duty;
uint32_t ICC2Capture;
uint32_t ICC2Freq;
uint32_t ICC2Duty;
uint32_t ICC3Capture;
uint32_t ICC3Freq;
uint32_t ICC3Duty;
uint32_t ICC4Capture;
uint32_t ICC4Freq;
uint32_t ICC4Duty;
uint16_t ICC1ReadValue1;
uint16_t ICC1ReadValue2;
uint16_t ICC1ReadValue3;
uint16_t ICC1ReadValue4;
uint16_t ICC2ReadValue1;
uint16_t ICC2ReadValue2;
uint16_t ICC2ReadValue3;
uint16_t ICC2ReadValue4;
uint16_t ICC3ReadValue1;
uint16_t ICC3ReadValue2;
uint16_t ICC3ReadValue3;
uint16_t ICC3ReadValue4;
uint16_t ICC4ReadValue1;
uint16_t ICC4ReadValue2;
uint16_t ICC4ReadValue3;
uint16_t ICC4ReadValue4;
uint8_t ICC1CaptureNumber;
uint8_t ICC2CaptureNumber;
uint8_t ICC3CaptureNumber;
uint8_t ICC4CaptureNumber;
void (* ItUpFcn)(void);
void (* ItTrgFcn)(void);
void (* ItComFcn)(void);
void (* ItBrkFcn)(void);
void (* ItCcFcn)(TIM_HandleTypeDef *htim);
}TIM_DataLinkTypeDef;

typedef enum
{
OUTPUT_COMP = 0,
OUTPUT_PWM ,
OUTPUT_TRGO ,
OUTPUT_FORCED ,
INPUT_PWM ,
INPUT_CAPTURE ,
INPUT_ETR ,
INPUT_ENCODER ,
INPUT_HALL_SENSOR ,
UNKNOWN
}TIM_ChTypeDef;

extern TIM_DataLinkTypeDef*   G_TIM_Data;      /* Pointer to TIMER data information*/
extern TIM_HandleTypeDef*     G_TIM_Handler;   /* Pointer to TIMER handler */
/* TIM4 handler */
extern TIM_HandleTypeDef htim4;
/* TIM4 data information*/
extern TIM_DataLinkTypeDef   TIM4_DataLink;
#endif
