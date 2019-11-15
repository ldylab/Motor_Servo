#include "stdAfx.h"

void TIM1_PWM_Init(u16 arr,u16 psc) //7200 200
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); // ʹ�ܶ��r��1�����O�r�
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //ʹ��GPIO���O�r�ʹ��                               	

   //�O��ԓ���_���}��ݔ������,ݔ��TIM1 CH1��PWM�}�n����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;  //TIM_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�}�����nݔ��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; //�O������һ�������¼��b���ӵ��Ԅ��ع��d�������L�ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //�O���Á�����TIMx�r��l�ʳ������A���lֵ  �����l
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //�O���r犷ָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM����Ӌ��ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ����������ʼ��TIMx�ĕr�g������λ

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //�x�񶨕r��ģʽ:TIM�}�n�����{�uģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //���^ݔ��ʹ��
	//TIM_OCInitStructure.TIM_Pulse = 0; //�O�����b�벶�@���^���������}�nֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //ݔ���O��:TIMݔ�����^�O�Ե�
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ����������ʼ�����OTIMx
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ����������ʼ�����OTIMx
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ����������ʼ�����OTIMx
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ����������ʼ�����OTIMx
	
  TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE ��ݔ��ʹ��	
	
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1
}

void servo_angle(int servo_num, uint16_t angle)
{
  uint16_t pulse;
  
  //ᘌ���C���D�Ƕ���ݗ
  if(angle <= 2)
    angle = 2;
  if(angle >= 178)
    angle = 178;
  //���Ƕ�ֵ�D�Q���}�nֵ  
  pulse = (uint16_t)(50 + angle * 100/90.0);  //���D�Q��ʽ�����pwm��arr��psc���Á�������׃��
	switch(servo_num)
	{
		case 1: TIM_SetCompare1(TIM1, pulse);
		break;
		case 2: TIM_SetCompare2(TIM1, pulse);
		break;
		case 3: TIM_SetCompare3(TIM1, pulse);
		break;
		case 4: TIM_SetCompare4(TIM1, pulse);
		break;
	}
}
