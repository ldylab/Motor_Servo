#ifndef __INPUT_H
#define __INPUT_H
#include "stm32f10x.h"

void Input_Init(void);

#define INPUT1 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11)		//��ȡGPIOC13������//
#define INPUT2 GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)		//��ȡGPIOE0������//
#define INPUT3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)		//��ȡGPIOC13������//

#endif
