/*
 * File: PWM_F401RE_Nucleo_it.c
 *
 * Generated by STM32 Coder for Xcos with scilab-5.5.2
 * C/C++ source code generated on  :05-Oct-2020
 *
 * Model version      : 1.0
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

/* ---- Headers ---- */
#include "PWM_F401RE_Nucleo_it.h"

/*******************************************************************************
* Function Name  : TIM4_ItCcFcn
* Description    : TIM4  capture compare event interrupt
* Input          : None
*******************************************************************************/
void TIM4_ItCcFcn(TIM_HandleTypeDef *htim)
{
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
   }
  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3) {
   }
   }
/*******************************************************************************
* Function Name  : TIM4_ItUpFcn
* Description    : TIM4 update interrupt
* Input          : None
* TIM4_ItUpFcn is called from HAL_TIM_PeriodElapsedCallback function
* in modelName_TIMER.c file.
*******************************************************************************/
void TIM4_ItUpFcn()
{
   }
