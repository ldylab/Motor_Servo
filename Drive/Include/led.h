#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

/*---------------------- LED配置宏 ------------------------*/

#define LED1_PIN             GPIO_Pin_0        		 // LED1 引脚      
#define LED1_PORT            GPIOC                  // LED1 GPIO端口     
#define LED1_CLK             RCC_APB2Periph_GPIOC	 // LED1 GPIO端口时钟

#define LED2_PIN             GPIO_Pin_1        		 // LED2 引脚      
#define LED2_PORT            GPIOC                  // LED2 GPIO端口     
#define LED2_CLK             RCC_APB2Periph_GPIOC	 // LED2 GPIO端口时钟

/*---------------------- LED控制宏 ------------------------*/
					
#define LED1_ON 	  GPIO_ResetBits(LED1_PORT,LED1_PIN);	// 输出低电平，点亮LED1	
#define LED1_OFF 	  GPIO_SetBits(LED1_PORT,LED1_PIN);		// 输出高电平，关闭LED1	

#define LED2_ON 	  GPIO_ResetBits(LED2_PORT,LED2_PIN);	// 输出低电平，点亮LED1	
#define LED2_OFF 	  GPIO_SetBits(LED2_PORT,LED2_PIN);		// 输出高电平，关闭LED1	

/*---------------------- 函数声明 ----------------------------*/

void LED_Init(void);	//LED初始化函数


#endif //__LED_H

