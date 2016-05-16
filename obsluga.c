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
