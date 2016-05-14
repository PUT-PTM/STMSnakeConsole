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



int gameover;// 0 - false 1-true
int x, y, fruitX, fruitY, score, dir1, ntail;
int tailX[100], tailY[100];
//int Direction { STOP = 0, RIGHT, LEFT, UP, DOWN };
int dir; // STOP = 0, RIGHT -1, LEFT - 2, UP - 3, DOWN - 4



const int szerokosc=78;
const int wysokosc=35;

void draw()
{
	PCD8544_Clear();
	int i;
	for(i=0; i<=szerokosc; i++)
	{
		PCD8544_GotoXY(i, 0);
		PCD8544_Puts("_",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
	for(i=4; i<=wysokosc; i++)
	{
		PCD8544_GotoXY(0, i);
		PCD8544_Puts("|",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
		PCD8544_GotoXY(80, i);
		PCD8544_Puts("|",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

	}
	for(i=1; i<=szerokosc-1; i++)
	{
		PCD8544_GotoXY(i, 35);
		PCD8544_Puts("_",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
	PCD8544_GotoXY(10,41);
	PCD8544_Puts("WYNIK: ",PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	int j;
	for(i=0;i<szerokosc;i++)
	{
		for(j=0;j<wysokosc;j++)
		{
			if(x==i&&y==j)
			{
				PCD8544_GotoXY(i, j);
				PCD8544_Puts("x",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			}
			int k;
			for(k=0;k<100;k++)
			{
				if(tailX[k]==i&&tailY[k]==j)
				{
					PCD8544_GotoXY(i, j);
					PCD8544_Puts("o",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
				}
			}
		}

	}
	PCD8544_Refresh();
	while(1)
	{}
}


void setup()
{
//	gameover = false;
	//dir = STOP;
	x = szerokosc / 2;
	y = 15;
	//fruitX = rand() % width;
	//fruitY = rand() % height;
	score = 0;
}
