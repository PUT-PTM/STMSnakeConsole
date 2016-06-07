#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_pcd8544.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4_discovery_lis302dl.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_adc.h"
#include "misc.h"


int main(void)
{

    SystemInit();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    initDiody();
   	initPrzycisk();
   	initTimer();
   	initAkcelerometr();
    PCD8544_Init(0x38);
    menu();





}
