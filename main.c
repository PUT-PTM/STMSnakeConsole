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





int main(void) {
    //180MHz
    SystemInit();
    initDiody();
   	initPrzycisk();
   	initAkcelerometr();
    PCD8544_Init(0x38);
    start();


   	GPIO_ResetBits(GPIOD,GPIO_Pin_All);
/*

for(;;)
   	{
   		if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update))
   		{
   			GPIO_SetBits(GPIOD,GPIO_Pin_14);
   			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
   		}
   		if(TIM2->CNT>2000)
   		{
   			GPIO_ResetBits(GPIOD,GPIO_Pin_All);
   		}

   		//    	  Opis:
   		  //  	  -TIM_GetFlagStatus(TIMER, TIM_FLAG_Update)  przepe³nienie timera
   		    //	  -za kazdym razem po TIM_GetFlagStatus(xx) trzeba daæ w warunku TIM_ClearFlag(TIMER, TIM_FLAG_Update);
   		    	//  -CNT aktualny period


	}

*/
/*
   	for(;;)
    {

   		float os_x=akcelerometr_osx();
   		float os_y=akcelerometr_osy();
   		if(os_x>1) GPIO_SetBits(GPIOD,GPIO_Pin_14);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_14);
    	if(os_x<-1) GPIO_SetBits(GPIOD,GPIO_Pin_12);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_12);
    	if(os_y>1) GPIO_SetBits(GPIOD,GPIO_Pin_13);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_13);
    	if(os_y<-1) GPIO_SetBits(GPIOD,GPIO_Pin_15);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_15);
    }

for(;;){
    		b= przycisk(b);
    		if(b==1)
    		{
    			GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    		}
    		else
    		{
    			GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    		}
}
*/
}
