#include "stdAfx.h"

void TIM1_PWM_Init(u16 arr,u16 psc) //7200 200
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); // 使能定時器1的外設時鐘
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIO外設時鐘使能                               	

   //設定該引腳為複用輸出功能,輸出TIM1 CH1的PWM脈衝波形
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;  //TIM_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //複用推輓輸出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = arr; //設定在下一個更新事件裝入活動的自動重灌載暫存器週期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler = psc; //設定用來作為TIMx時鐘頻率除數的預分頻值  不分頻
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //設定時鐘分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上計數模式
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根據TIM_TimeBaseInitStruct中指定的引數初始化TIMx的時間基數單位

 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //選擇定時器模式:TIM脈衝寬度調製模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比較輸出使能
	//TIM_OCInitStructure.TIM_Pulse = 0; //設定待裝入捕獲比較暫存器的脈衝值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //輸出極性:TIM輸出比較極性低
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //根據TIM_OCInitStruct中指定的引數初始化外設TIMx
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //根據TIM_OCInitStruct中指定的引數初始化外設TIMx
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //根據TIM_OCInitStruct中指定的引數初始化外設TIMx
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //根據TIM_OCInitStruct中指定的引數初始化外設TIMx
	
  TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE 主輸出使能	
	
	TIM_Cmd(TIM1, ENABLE);  //使能TIM1
}

void servo_angle(int servo_num, uint16_t angle)
{
  uint16_t pulse;
  
  //針對舵機可轉角度限輻
  if(angle <= 2)
    angle = 2;
  if(angle >= 178)
    angle = 178;
  //將角度值轉換為脈衝值  
  pulse = (uint16_t)(50 + angle * 100/90.0);  //此轉換公式需根據pwm的arr及psc配置來做相應變化
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
