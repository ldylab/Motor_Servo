#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "delay.h"

#define	KEY_ON	 1		//按键按下
#define	KEY_OFF	 0		//按键放开

/*---------------------- 按键配置宏 ------------------------*/

#define KEY_PIN           GPIO_Pin_2        		 // KEY 引脚      
#define KEY_PORT          GPIOC                  // KEY GPIO端口     
#define KEY_CLK           RCC_APB2Periph_GPIOC	 // KEY GPIO端口时钟

/*---------------------- 函数声明 ----------------------------*/

void 	KEY_Init(void);	//按键IO口初始化函数
u8		KEY_Scan(void);   //按键扫描

unsigned char User_KEY_Scan(unsigned char mode);
void User_KEY_Init(void);
unsigned char User_KEY_Scan_1(unsigned char mode);
unsigned char User_KEY_Scan_2(unsigned char mode);
unsigned char User_KEY_Scan_3(unsigned char mode);

#endif //__KEY_H


