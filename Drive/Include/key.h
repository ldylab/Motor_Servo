#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"
#include "delay.h"

#define	KEY_ON	 1		//��������
#define	KEY_OFF	 0		//�����ſ�

/*---------------------- �������ú� ------------------------*/

#define KEY_PIN           GPIO_Pin_2        		 // KEY ����      
#define KEY_PORT          GPIOC                  // KEY GPIO�˿�     
#define KEY_CLK           RCC_APB2Periph_GPIOC	 // KEY GPIO�˿�ʱ��

/*---------------------- �������� ----------------------------*/

void 	KEY_Init(void);	//����IO�ڳ�ʼ������
u8		KEY_Scan(void);   //����ɨ��

unsigned char User_KEY_Scan(unsigned char mode);
void User_KEY_Init(void);
unsigned char User_KEY_Scan_1(unsigned char mode);
unsigned char User_KEY_Scan_2(unsigned char mode);
unsigned char User_KEY_Scan_3(unsigned char mode);

#endif //__KEY_H


