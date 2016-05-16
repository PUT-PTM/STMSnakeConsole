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
#include "menu.h"


void initPrzycisk()
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line1;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE; EXTI_Init(&EXTI_InitStructure);
	SYSCFG_EXTILineConfig(GPIOD, EXTI_PinSource1);
}
void initDiody()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
   	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
   	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
   	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void initAkcelerometr()
{
	LIS302DL_InitTypeDef AccInitStr;
	AccInitStr.Axes_Enable = LIS302DL_XYZ_ENABLE;
	AccInitStr.Full_Scale = LIS302DL_FULLSCALE_2_3;
	AccInitStr.Power_Mode = LIS302DL_LOWPOWERMODE_ACTIVE;
	AccInitStr.Output_DataRate = LIS302DL_DATARATE_100;
	AccInitStr.Self_Test = LIS302DL_SELFTEST_NORMAL;
	LIS302DL_Init(&AccInitStr);
}
void initTimer()
{
	SystemCoreClockUpdate();
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period=6719;           //period 32 bitowy
    TIM_TimeBaseStructure.TIM_Prescaler=9999;		//prescaler 16bitowy
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode =   TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    TIM_TimeBaseStructure.TIM_Period= 1679;            //period 32 bitowy
    TIM_TimeBaseStructure.TIM_Prescaler=9999;		//prescaler 16bitowy
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode =   TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    //TIM_Cmd(TIM3, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
    TIM_TimeBaseStructure.TIM_Period=2000;           //period 32 bitowy
    TIM_TimeBaseStructure.TIM_Prescaler=9999;		//prescaler 16bitowy
    TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode =   TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

}
