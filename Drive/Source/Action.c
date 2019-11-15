#include "stdAfx.h"

#define Shooting_Servo_Back_Angle 150 //射球推球舵机回到后面的角度
#define Shooting_Servo_Push_Angle 150 //射球推球舵机去推球的角度

#define Catching_Servo_Open_Angle 150 //夹球舵机打开夹子的角度
#define Catching_Servo_Close_Angle 150 //夹球舵机关闭夹子的角度

#define Raising_Servo_Up_Angle 150 //20千克抬升舵机抬升角度
#define Raising_Servo_Down_Angle 150 //20千克抬升舵机放下角度

#define Filping_Servo_Up_Angle 150 //倒球舵机倒球角度
#define Filping_Servo_Down_Angle 150 //倒球舵机放下角度

int temp_data_1 = 0, temp_data_2 = 0;
unsigned char data_1_char[3], data_2_char[3];

int key_1, key_2, key_3;
int input_state;

void Input_display(void)
{
	key_1 = User_KEY_Scan_1(0);
	if(key_1 == 1)
	{
		temp_data_1++;
		if(temp_data_1 >= 99)
		{
			temp_data_1 = 99;
		}
	}
	else if(key_1 == 2)
	{
		temp_data_1--;
		if(temp_data_1 <= 0)
		{
			temp_data_1 = 0;
		}
	}
	
	key_2 = User_KEY_Scan_2(0);
	if(key_2 == 3)
	{
		temp_data_2++;
		if(temp_data_2 >= 99)
		{
			temp_data_2 = 99;
		}
	}
	else if(key_2 == 4)
	{
		temp_data_2--;
		if(temp_data_2 <= 0)
		{
			temp_data_2 = 0;
		}
	}
	
	key_3 = User_KEY_Scan_3(0);
	if(key_3 == 0)
	{
	}
	else if(key_3 == 5)
	{
		Int_To_Str(temp_data_2, data_2_char);
		STMFLASH_Write(FLASH_SAVE_ADDR_2, (u16*)data_2_char, sizeof(data_2_char));
		Int_To_Str(temp_data_1, data_1_char);
		STMFLASH_Write(FLASH_SAVE_ADDR_1, (u16*)data_1_char, sizeof(data_1_char));
		OLED_CLS();
		Delay_ms(10);
		OLED_ShowStr(42,3,(unsigned char*)"OK!OK!",2);
		Delay_ms(400);
		OLED_CLS();
		Delay_ms(10);
	}
	OLED_ShowStr(15,1,(unsigned char*)"L_Speed = ",2);
	OLED_ShowNum(91,1,temp_data_1,2);
	OLED_ShowStr(15,4,(unsigned char*)"R_Speed = ",2);
	OLED_ShowNum(91,4,temp_data_2,2);
}

int Input_data(void)
{
	int input_state;
	if(INPUT1 == 0 && INPUT2 == 0 && INPUT3 == 0)
	{
		input_state = 0;
	}
	else if(INPUT1 == 0 && INPUT2 == 0 && INPUT3 == 1)
	{
		input_state = 1;
	}
	else if(INPUT1 == 0 && INPUT2 == 1 && INPUT3 == 0)
	{
		input_state = 2;
	}
	else if(INPUT1 == 0 && INPUT2 == 1 && INPUT3 == 1)
	{
		input_state = 3;
	}
	else if(INPUT1 == 1 && INPUT2 == 0 && INPUT3 == 0)
	{
		input_state = 4;
	}
	else if(INPUT1 == 1 && INPUT2 == 0 && INPUT3 == 1)
	{
		input_state = 5;
	}
	else if(INPUT1 == 1 && INPUT2 == 1 && INPUT3 == 0)
	{
		input_state = 6;
	}
	else if(INPUT1 == 1 && INPUT2 == 1 && INPUT3 == 1)
	{
		input_state = 7;
	}
	return input_state;
}

void Shooting_prepare(void)
{
	servo_angle(1, Shooting_Servo_Back_Angle);	
	GPIO_ResetBits(GPIOB, SecBIN2);
	GPIO_SetBits(GPIOC, SecBIN1);
	TIM_SetCompare3(TIM8,71 * temp_data_1);	
	GPIO_SetBits(GPIOB, SecAIN1);
	GPIO_ResetBits(GPIOB, SecAIN2);
	TIM_SetCompare1(TIM8,71 * temp_data_2);
}

void Shooting_go(void)
{
	servo_angle(1, Shooting_Servo_Push_Angle);	
	GPIO_ResetBits(GPIOB, SecBIN2);
	GPIO_SetBits(GPIOC, SecBIN1);
	TIM_SetCompare3(TIM8,71 * temp_data_1);	
	GPIO_SetBits(GPIOB, SecAIN1);
	GPIO_ResetBits(GPIOB, SecAIN2);
	TIM_SetCompare1(TIM8,71 * temp_data_2);
}

void Catching_servo_close(void)
{
	servo_angle(2, Catching_Servo_Close_Angle);	
}

void Catching_servo_open(void)
{
	servo_angle(2, Catching_Servo_Open_Angle);	
}

void Raising_servo_up(void)
{
	servo_angle(3, Raising_Servo_Up_Angle);
}

void Raising_servo_down(void)
{
	servo_angle(3, Raising_Servo_Down_Angle);
}

void Flip_servo_up(void)
{
	servo_angle(4, Filping_Servo_Up_Angle);
}

void Filp_servo_down(void)
{
	servo_angle(4, Filping_Servo_Down_Angle);
}

void Swallowing(void)
{
	servo_angle(1, Shooting_Servo_Back_Angle);
	GPIO_SetBits(GPIOB, SecBIN2);
	GPIO_ResetBits(GPIOC, SecBIN1);
	TIM_SetCompare3(TIM8,2000);	
	GPIO_ResetBits(GPIOB, SecAIN1);
	GPIO_SetBits(GPIOB, SecAIN2);
	TIM_SetCompare1(TIM8,2000);
}

