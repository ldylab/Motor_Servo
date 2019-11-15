#ifndef __MOTORDRIVE_H
#define __MOTORDRIVE_H
#include "stm32f10x.h"

#define SecAIN1 GPIO_Pin_5
#define SecAIN2 GPIO_Pin_9
#define SecBIN1 GPIO_Pin_12
#define SecBIN2 GPIO_Pin_3

void  GPIO_Configuration(void);
void TIM8_PWM_Init(u16 arr, u16 psc);

#endif
