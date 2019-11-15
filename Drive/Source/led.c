/***
	***************************************************************************
	*	@file  	led.c
	*	@version V1.0.0
	*	@brief   LED接口相关函数
   ***************************************************************************
   *  @description
	*
	*  初始化LED的IO口，配置为推挽输出、上拉、速度等级2M。
	* 	
	***************************************************************************
***/

#include "stdAfx.h"

// 函数：LED IO口初始化
//
void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	RCC_APB2PeriphClockCmd ( LED1_CLK | LED2_CLK, ENABLE); 	//初始化GPIO时钟	
				
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	
	
	//初始化 LED1 引脚
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	 
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);	

	//初始化 LED2 引脚
	GPIO_InitStructure.GPIO_Pin = LED2_PIN;	 
	GPIO_Init(LED2_PORT, &GPIO_InitStructure);	
	
	GPIO_ResetBits(LED1_PORT,LED1_PIN);  //IO口输出低电平
	GPIO_ResetBits(LED2_PORT,LED2_PIN);  //IO口输出低电平	
}

