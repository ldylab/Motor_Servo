#ifndef __TIMER_H
#define __TIMER_H
#include "stm32f10x.h"
#include "PID_cal_tim6.h"

void TIM6_Int_Init(u16 arr,u16 psc);
#endif
