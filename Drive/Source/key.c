/***
	***************************************************************************
	*	@file  	key.c
	*	@version V1.0.0
	*	@brief   �����ӿ���غ���
   ***************************************************************************
   *  @description
	*
	*  ��ʼ���������ţ�����Ϊ�������롢�ٶȵȼ�2M��
	* 	
	***************************************************************************
***/

#include "stdAfx.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_0)		//��ȡGPIOC13������//
#define KEY3 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1)		//��ȡGPIOE0������//
#define KEY0 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_2)		//��ȡGPIOC13������//
#define KEY4 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)		//��ȡGPIOE0������
#define KEY2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)		//��ȡGPIOC13������//

#define KEY0_PRESS	1			
#define KEY1_PRESS  2
#define KEY2_PRESS	3			
#define KEY3_PRESS  4
#define KEY4_PRESS	5		

// ����������IO�ڳ�ʼ��
//
void KEY_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	RCC_APB2PeriphClockCmd ( KEY_CLK, ENABLE); 	//��ʼ��KEYʱ��	
	
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; //�ٶ�ѡ��
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
	
	GPIOInit.GPIO_Mode = GPIO_Mode_IPU;		//��������
	GPIOInit.GPIO_Pin = GPIO_Pin_8;
	GPIOInit.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIOInit);
}

unsigned char User_KEY_Scan_1(unsigned char mode)
{
	static unsigned char key_up = 1;    //�����ɿ���־
	
	if(mode)
	{
		key_up = 1;						//֧��������
	}
	
	if(key_up && (KEY0 == 0 || KEY1 == 0))
	{
		Delay_ms(10);					//ȥ��
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
	return 0;		//�ް�������
}

unsigned char User_KEY_Scan_2(unsigned char mode)
{
	static unsigned char key_up = 1;    //�����ɿ���־
	
	if(mode)
	{
		key_up = 1;						//֧��������
	}
	
	if(key_up && (KEY2 == 0 || KEY3 == 0))
	{
		Delay_ms(10);					//ȥ��
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
	return 0;		//�ް�������
}

unsigned char User_KEY_Scan_3(unsigned char mode)
{
	static unsigned char key_up = 1;    //�����ɿ���־
	
	if(mode)
	{
		key_up = 1;						//֧��������
	}
	
	if(key_up && (KEY4 == 0 || KEY3 == 0))
	{
		Delay_ms(10);					//ȥ��
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
	return 0;		//�ް�������
}


// ����������ɨ��
//	���أ�KEY_ON - �������£�KEY_OFF - �����ſ� 
//			
u8	KEY_Scan(void)
{
	if( GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0 )	//��ⰴ���Ƿ񱻰���
	{	
		Delay_ms(10);	//��ʱ����
		if(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0)	//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(GPIO_ReadInputDataBit ( KEY_PORT,KEY_PIN) == 0);	//�ȴ������ſ�
			return KEY_ON;	//���ذ������±�־
		}
	}
	return KEY_OFF;	
}


