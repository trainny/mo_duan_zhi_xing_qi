#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

extern TIM_HandleTypeDef TIM2_Handler;      //定时器2句柄 
extern TIM_HandleTypeDef TIM3_Handler;      //定时器3句柄 
extern TIM_OC_InitTypeDef 	TIM3_CH2Handler;		//定时器3通道2句柄



void TIM2_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM_SetTIM3Compare2(u32 compare);

#endif

