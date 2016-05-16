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
<<<<<<< HEAD
int dir; // STOP = 0, RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4

const int gorna_sciana=4;
const int dolna_sciana=34;
const int lewa_sciana=0;
const int prawa_sciana=78;

void draw()
{
	//PCD8544_Clear();
	int i;
	for(i=lewa_sciana; i<=prawa_sciana; i++)
=======
int dir; // STOP = 0, RIGHT -1, LEFT - 2, UP - 3, DOWN - 4



const int szerokosc=78;
const int wysokosc=35;

void draw()
{
	PCD8544_Clear();
	int i;
	for(i=0; i<=szerokosc; i++)
>>>>>>> origin/master
	{
		PCD8544_GotoXY(i, 0);
		PCD8544_Puts("_",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
<<<<<<< HEAD
	for(i=gorna_sciana; i<=dolna_sciana+1; i++)
=======
	for(i=4; i<=wysokosc; i++)
>>>>>>> origin/master
	{
		PCD8544_GotoXY(0, i);
		PCD8544_Puts("|",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
		PCD8544_GotoXY(80, i);
		PCD8544_Puts("|",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);

	}
<<<<<<< HEAD
	for(i=lewa_sciana+1; i<=prawa_sciana-1; i++)
=======
	for(i=1; i<=szerokosc-1; i++)
>>>>>>> origin/master
	{
		PCD8544_GotoXY(i, 35);
		PCD8544_Puts("_",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	}
	PCD8544_GotoXY(10,41);
	PCD8544_Puts("WYNIK: ",PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	int j;
<<<<<<< HEAD
	for(i=0;i<prawa_sciana;i++)
	{
		for(j=0;j<dolna_sciana+1;j++)
=======
	for(i=0;i<szerokosc;i++)
	{
		for(j=0;j<wysokosc;j++)
>>>>>>> origin/master
		{
			if(x==i&&y==j)
			{
				PCD8544_GotoXY(i, j);
<<<<<<< HEAD
				PCD8544_Puts("X",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
			}
			if(fruitX==i&&fruitY==j)
			{
				PCD8544_GotoXY(i, j);
				PCD8544_Puts("f",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
=======
				PCD8544_Puts("x",PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
>>>>>>> origin/master
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
<<<<<<< HEAD
	}
	PCD8544_Refresh();

=======

	}
	PCD8544_Refresh();
	while(1)
	{}
>>>>>>> origin/master
}


void setup()
{
<<<<<<< HEAD
	gameover = 0;
	dir = 1;
	x = 15;
	y = 15;
	fruitX = 22;
	fruitY = 22;
	score = 0;
}

int logic(int kierunek)
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	dir=kierunek;
	switch (dir)
	{
	case 2:
		x--;
		break;
	case 1:
		x++;
		break;
	case 3:
		y--;
		break;
	case 4:
		y++;
	default:
		break;
	}

	if (x > prawa_sciana || x<lewa_sciana || y>dolna_sciana || y < gorna_sciana)
		gameover = 1;

	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == x&&tailY[i] == y)
			gameover = 1;
	}

	if (x == fruitX && y == fruitY)
	{
		score = +10;
		//fruitX = rand() % width;
		//fruitY = rand() % height;
		ntail++;
	}
	if(gameover==1)
	{
		return 1;
	}
	else return 0;
}

=======
//	gameover = false;
	//dir = STOP;
	x = szerokosc / 2;
	y = 15;
	//fruitX = rand() % width;
	//fruitY = rand() % height;
	score = 0;
}
>>>>>>> origin/master
