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

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
		os_x=akcelerometr_osx();
		os_y=akcelerometr_osy();
		if(os_x<-10)
		{
			kier=2;
		}
		if(os_x>10)
		{
			kier=1;
		}
		if(os_y<-10)
		{
			kier=4;
		}
		if(os_y>10)
		{
			kier=3;
		}
    }
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}



void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
		int lastkier=kier;
		os_x=akcelerometr_osx();
		os_y=akcelerometr_osy();
		if(os_x<-10)
		{
			kier=2;
			if(lastkier==1)
			kier=1;
			os_y=0;
		}
		if(os_x>10)
		{
				kier=1;
				if(lastkier==2)
					kier=2;
					os_y=0;
		}
		if(os_y<-10)
		{
			kier=4;
			if(lastkier==3)
			kier=3;
			os_x=0;
		}
		if(os_y>10)
		{
			kier=3;
			if(lastkier==4)
			kier=4;
			os_x=0;
		}
		status_gry=logic(kier);
		PCD8544_Clear();
		draw();
    }
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
}


