#ifndef __INPUT_H
#define __INPUT_H
#include "stm32f10x.h"

void Input_Init(void);

#define INPUT1 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11)		//读取GPIOC13的输入//
#define INPUT2 GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_2)		//读取GPIOE0的输入//
#define INPUT3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)		//读取GPIOC13的输入//

#endif
