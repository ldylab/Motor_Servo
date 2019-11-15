#include "stdAfx.h"

int main(void)
{
	Delay_Init(); //延时控制
	LED_Init(); //一共有两个灯(LED1_ON, LED2_OFF)
  KEY_Init(); //按键输入
	GPIO_Configuration();
	I2C_Configuration();
	OLED_Init();
	OLED_CLS();
	Input_Init();
	User_KEY_Init();
	Delay_ms(100);
	TIM8_PWM_Init(7199, 0);
	TIM1_PWM_Init(199, 719);
	
	STMFLASH_Read(FLASH_SAVE_ADDR_1, (u16*)data_1_char, SIZE_EEPROM);
	temp_data_1 = atoi(data_1_char);
	STMFLASH_Read(FLASH_SAVE_ADDR_2, (u16*)data_2_char, SIZE_EEPROM);
	temp_data_2 = atoi(data_2_char);
	
	while(1)
	{		
		Input_display(); //输入与显示，这个不要动
		
		/*拥有的动作
		Shooting_prepare();
		Shooting_go();
		Catching_servo_close();
		Catching_servo_open();
		Raising_servo_up();
		Raising_servo_down();
		Fliping_servo_up();
		Filping_servo_down();
		Swallowing();
		*/
		
		switch(Input_data())
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
	}
}
