#ifndef __SERVO_H
#define __SERVO_H
#include "stm32f10x.h"

void TIM1_PWM_Init(u16 arr,u16 psc);
void servo_angle(int servo_num, uint16_t angle);

#endif
