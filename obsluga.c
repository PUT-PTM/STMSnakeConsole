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



int przycisk(int a)
{
	int b=a;
	a=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
	for(int i=0;i<3000000;i++){}

	if(a==0)
	{
		return b;
	}
	else
	{
		if(b==1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

float akcelerometr_osx()
{
	int8_t acc_x;
	for(int i = 0; i < 10000; i++) {}
	LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);
	return (acc_x*2.3*9.81)/127; // os x
}

float akcelerometr_osy()
{
	int8_t acc_y;
	for(int i = 0; i < 10000; i++) {}
	LIS302DL_Read(&acc_y,LIS302DL_OUT_Y_ADDR,1);
	return (acc_y*2.3*9.81)/127; // os y
}

float akcelerometr_osz()
{
	int8_t acc_z;
	for(int i = 0; i < 10000; i++) {}
	LIS302DL_Read(&acc_z,LIS302DL_OUT_Z_ADDR,1);
	return (acc_z*2.3*9.81)/127; // os z
}
