#include "PID_cal_tim6.h"
#include "Timer.h"

int timer_count = 0; 
void TIM6_IRQHandler(void)  //TIM6�ж� ������������� PID����
{
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);  //���TIMx���жϴ�����λ:TIM �ж�Դ 
		timer_count++;
		//printf("Time is = %d\r\n", timer_count);
	}
}