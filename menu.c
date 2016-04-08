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



void start()
{
	PCD8544_GotoXY(14, 3);
    PCD8544_Puts("SNAKE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
    PCD8544_GotoXY(10, 14);
    PCD8544_Puts("Paulina Kurpisz", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(10, 27);

	PCD8544_Puts("Michal Suchorzynski", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
    PCD8544_Refresh();
    int b=0;
    while(b==0)
    {
    	b=przycisk(b);
    }
    PCD8544_Clear();
    PCD8544_Refresh();
    menu();
}

void menu()
{
	PCD8544_GotoXY(0,10);
	PCD8544_Puts("    START", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,20);
	PCD8544_Puts("    REKORD", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,30);
	PCD8544_Puts("    OPCJE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,40);
	PCD8544_Puts("    ZAKONCZ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Refresh();

	float a=0;
	int b=10;
	int b2;

	while(1)
	{
		PCD8544_GotoXY(0,b);
		PCD8544_Puts("-->", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
		PCD8544_Refresh();
		for(int i=0;i<30000000;i++){}

		a=akcelerometr_osx();
		if(a<-2 && b!=10)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			a=0;
		}
		if(a>2&& b!=40)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b+10;
			a=0;
		}
		a=0;
	}
}
