#include "stdAfx.h"

void Input_Init(void)
{
	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); 
	
	//C11
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = GPIO_Pin_11;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIOInit);
	
	//B4
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入
	GPIOInit.GPIO_Pin = GPIO_Pin_4;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInit);
	
	//D2
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入
	GPIOInit.GPIO_Pin = GPIO_Pin_2;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIOInit);
}
