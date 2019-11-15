#include "PID_cal_tim6.h"
#include "Timer.h"

int timer_count = 0; 
void TIM6_IRQHandler(void)  //TIM6中断 编码器电机计数 PID计算
{
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);  //清除TIMx的中断待处理位:TIM 中断源 
		timer_count++;
		//printf("Time is = %d\r\n", timer_count);
	}
}