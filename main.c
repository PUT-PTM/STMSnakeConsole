#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_pcd8544.h"
#include "stm32f4xx_conf.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4_discovery_lis302dl.h"
#include "stm32f4xx_rcc.h"


int8_t acc_x,acc_y,acc_z;

int main(void) {
    //180MHz
    SystemInit();

    /* GPIOD Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);



    GPIO_InitTypeDef  GPIO_InitStructure;
   	// Diody
   	/* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */
   	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
   	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
   	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
   	GPIO_Init(GPIOD, &GPIO_InitStructure);


   	//Akcelerometr
   	LIS302DL_InitTypeDef LIS302DL_InitStruct;
   	LIS302DL_InitStruct.Power_Mode=LIS302DL_LOWPOWERMODE_ACTIVE;
   	LIS302DL_InitStruct.Output_DataRate=LIS302DL_DATARATE_100;
   	LIS302DL_InitStruct.Axes_Enable=LIS302DL_XYZ_ENABLE;
   	LIS302DL_InitStruct.Full_Scale=LIS302DL_FULLSCALE_2_3;
   	LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
   	LIS302DL_Init(&LIS302DL_InitStruct);


    //Initialize LCD with 0x38 software contrast
    PCD8544_Init(0x38);

    //Go to x=14, y=3 position
    PCD8544_GotoXY(14, 3);

    //Print data with Pixel Set mode and Fontsize of 5x7px
    PCD8544_Puts("STM32F429", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
    PCD8544_GotoXY(15, 13);
    PCD8544_Puts("Discovery", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
    PCD8544_GotoXY(30, 26);
    PCD8544_Puts("2014", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

    PCD8544_GotoXY(45, 42);
    //Put string with Pixel set mode and Fontsize of 3x5
    PCD8544_Puts("majerle.eu", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

    //Display data on LCD
    PCD8544_Refresh();
   	unsigned int i;
   	int b=0;
    for(;;)
    {
    	for(int i = 0; i < 10000; i++) {}
   		LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);
   		LIS302DL_Read(&acc_y,LIS302DL_OUT_Y_ADDR,1);
   		LIS302DL_Read(&acc_z,LIS302DL_OUT_Z_ADDR,1);
   		float os_x = (acc_x*2.3*9.81)/127;
    	float os_y = (acc_y*2.3*9.81)/127;
    	float os_z = (acc_z*2.3*9.81)/127;

    	if(os_x>1) GPIO_SetBits(GPIOD,GPIO_Pin_14);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_14);
    	if(os_x<-1) GPIO_SetBits(GPIOD,GPIO_Pin_12);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_12);
    	if(os_y>1) GPIO_SetBits(GPIOD,GPIO_Pin_13);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_13);
    	if(os_y<-1) GPIO_SetBits(GPIOD,GPIO_Pin_15);
    	else GPIO_ResetBits(GPIOD,GPIO_Pin_15);

    /*		a=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
    		for(int i=0;i<3000000;i++){}


    		if(a==1)
    		{
    			if(b==0)
    			{
    				b=1;
    			}
    			else
    			{
    				b=0;
    			}
    			a=0;
    		}
    		if(b==0)
    		{
    			GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    		}
    		else
    		{
    			GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
    		}*/


}}