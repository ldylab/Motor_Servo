/***
	***************************************************************************
	*	@file  	key.c
	*	@version V1.0.0
	*	@brief   按键接口相关函数
   ***************************************************************************
   *  @description
	*
	*  初始化按键引脚，配置为上拉输入、速度等级2M。
	* 	
	***************************************************************************
***/

#include "stdAfx.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0)		//读取GPIOC13的输入//
#define KEY3 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1)		//读取GPIOE0的输入//
#define KEY0 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2)		//读取GPIOC13的输入//
#define KEY4 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)		//读取GPIOE0的输入
#define KEY2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)		//读取GPIOC13的输入//

#define KEY0_PRESS	1			
#define KEY1_PRESS  2
#define KEY2_PRESS	3			
#define KEY3_PRESS  4
#define KEY4_PRESS	5		

// 函数：按键IO口初始化
//
void KEY_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体
	RCC_APB2PeriphClockCmd ( KEY_CLK, ENABLE); 	//初始化KEY时钟	
	
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //速度选择
	GPIO_InitStructure.GPIO_Pin   = KEY_PIN;	 
	
	GPIO_Init(KEY_PORT, &GPIO_InitStructure);	

}	

void User_KEY_Init(void)
{
	GPIO_InitTypeDef GPIOInit;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;
	GPIOInit.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_13;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC, &GPIOInit);
	
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;		//上拉输入
	GPIOInit.GPIO_Pin = GPIO_Pin_8;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIOInit);
}

unsigned char User_KEY_Scan_1(unsigned char mode)
{
	static unsigned char key_up = 1;    //按键松开标志
	
	if(mode)
	{
		key_up = 1;						//支持连续按
	}
	
	if(key_up && (KEY0 == 0 || KEY1 == 0))
	{
		Delay_ms(10);					//去抖
		key_up = 0;
		if(KEY0 == 0)		
			return KEY0_PRESS;
		else if(KEY1 == 0)  
			return KEY1_PRESS;
	}
	else if(KEY0 == 1 && KEY1 == 1)
	{
		key_up = 1;
	}
	return 0;		//无按键按下
}

unsigned char User_KEY_Scan_2(unsigned char mode)
{
	static unsigned char key_up = 1;    //按键松开标志
	
	if(mode)
	{
		key_up = 1;						//支持连续按
	}
	
	if(key_up && (KEY2 == 0 || KEY3 == 0))
	{
		Delay_ms(10);					//去抖
		key_up = 0;
		if(KEY2 == 0)		
			return KEY2_PRESS;
		else if(KEY3 == 0)  
			return KEY3_PRESS;
	}
	else if(KEY2 == 1 && KEY3 == 1)
	{
		key_up = 1;
	}
	return 0;		//无按键按下
}

unsigned char User_KEY_Scan_3(unsigned char mode)
{
	static unsigned char key_up = 1;    //按键松开标志
	
	if(mode)
	{
		key_up = 1;						//支持连续按
	}
	
	if(key_up && (KEY4 == 0 || KEY3 == 0))
	{
		Delay_ms(10);					//去抖
		key_up = 0;
		if(KEY4 == 0)		
			return KEY4_PRESS;
		else if(KEY3 == 0)  
			return KEY3_PRESS;
	}
	else if(KEY4 == 1 && KEY3 == 1)
	{
		key_up = 1;
	}
	return 0;		//无按键按下
}


// 函数：按键扫描
//	返回：KEY_ON - 按键按下，KEY_OFF - 按键放开 
//			
u8	KEY_Scan(void)
{
	if( GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0 )	//检测按键是否被按下
	{	
		Delay_ms(10);	//延时消抖
		if(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0)	//再次检测是否为低电平
		{
			while(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0);	//等待按键放开
			return KEY_ON;	//返回按键按下标志
		}
	}
	return KEY_OFF;	
}


