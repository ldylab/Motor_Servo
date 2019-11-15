#ifndef __ACTION_H
#define __ACTION_H
#include "stm32f10x.h"

#define SIZE_EEPROM sizeof(data_1_char)
#define FLASH_SAVE_ADDR_1 0X08020000
#define FLASH_SAVE_ADDR_2 0X08030000

void Input_display(void);
int Input_data(void);

void Shooting_prepare(void);
void Shooting_go(void);
void Catching_servo_close(void);
void Catching_servo_open(void);
void Raising_servo_up(void);
void Raising_servo_down(void);
void Fliping_servo_up(void);
void Filping_servo_down(void);
void Swallowing(void);

extern int temp_data_1, temp_data_2;
extern unsigned char data_1_char[3], data_2_char[3];
#endif
