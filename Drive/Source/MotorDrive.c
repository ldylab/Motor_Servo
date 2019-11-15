#include "stdAfx.h"

/*��ʼ��GPIO���������С����I/O��*/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIOB_InitStructure;//��������GPIO_InitTypeDef���͵Ľṹ��
	GPIO_InitTypeDef GPIOC_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //����GPIOB����ʱ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	
	GPIOB_InitStructure.GPIO_Pin = SecAIN1 | SecAIN2 | SecBIN2;             //ѡ��Ҫ���Ƶ�GPIOB����
	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //��������ģʽΪ����ʽ���
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      //���������ٶ�Ϊ50MHz

	GPIO_Init(GPIOB, &GPIOB_InitStructure);                 //���ó�ʼ��GPIOB
	GPIO_SetBits(GPIOB, SecAIN1 | SecAIN2 | SecBIN2);                       //�����رյ��
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //����GPIOC����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  GPIOC_InitStructure.GPIO_Pin = SecBIN1;
	GPIOC_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       //��������ģʽΪ����ʽ���
	GPIOC_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIOC_InitStructure);
	GPIO_SetBits(GPIOC, SecBIN1);
}

/*��ʼ��TIM8��ʹ����PC6~9����PWM*/
void TIM8_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE); //ʹ�ܶ�ʱ��3ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_8; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
	//��ʼ��TIM8

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	//��ʼ��TIM8 Channel2 PWMģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset ;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low ; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM8, &TIM_OCInitStructure); //����Tָ���Ĳ�����ʼ������TIM8 OC2
	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); //ʹ��TIM8��CCR2�ϵ�Ԥװ�ؼĴ���
	//TIM_SetCompare1(TIM8,474);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset ;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low ; //�������:TIM����Ƚϼ��Ը�
	TIM_OC3Init(TIM8, &TIM_OCInitStructure); //����Tָ���Ĳ�����ʼ������TIM8 OC2
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable); //ʹ��TIM8��CCR2�ϵ�Ԥװ�ؼĴ���
	//TIM_SetCompare3(TIM8,900);
	
	TIM_Cmd(TIM8, ENABLE); //��ʹ��TIM8
	TIM_CtrlPWMOutputs(TIM8,ENABLE);
}
