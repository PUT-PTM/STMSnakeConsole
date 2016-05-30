#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4_discovery_lis302dl.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_adc.h"
#include "misc.h"
#include "menu.h"




int8_t akcelerometr_osx()
{
	int8_t acc_x;
	LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);
	return acc_x; // os x
}

int8_t akcelerometr_osy()
{
	int8_t acc_y;
	LIS302DL_Read(&acc_y,LIS302DL_OUT_Y_ADDR,1);
	return acc_y; // os y
}

int akcelerometr_osz()
{
	int8_t acc_z;
	LIS302DL_Read(&acc_z,LIS302DL_OUT_Z_ADDR,1);
	return acc_z; // os z
}


void EXTI1_IRQHandler(void)
{
	TIM_Cmd(TIM3, ENABLE);
}
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
		if(EXTI_GetITStatus(EXTI_Line1) != RESET)
		{
		    a=1;
		    EXTI_ClearITPendingBit(EXTI_Line1);
	   }
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		TIM_Cmd(TIM3, DISABLE);
		TIM_SetCounter(TIM3, 0);
    }
}

