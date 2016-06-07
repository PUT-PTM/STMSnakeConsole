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
int head_x, head_y, fruitX, fruitY, score, dir1, ntail;
int tailX[100], tailY[100];
//int Direction { STOP = 0, RIGHT, LEFT, UP, DOWN };
int dir; // STOP = 0, RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4

const int gorna_sciana=5;
const int dolna_sciana=35;
const int lewa_sciana=5;
const int prawa_sciana=79;

void draw_snake()
{
	// head
	int i;
	for(i=head_x;i>head_x-3;i--)
	{
		int j;
		for(j=head_y;j>head_y-3;j-- )
		{
		PCD8544_DrawPixel(i, j, PCD8544_Pixel_Set);
		}
	}
	//tail
	int k;
	for(k=0;k<ntail;k++)
	{
		for(i=tailX[k];i>tailX[k]-3;i--)
		{
				int j;
				for(j=tailY[k];j>tailY[k]-3;j-- )
				{
				PCD8544_DrawPixel(i, j, PCD8544_Pixel_Set);
				}
		}
	}
}

void draw_apple()
{
	int i;
	for(i=fruitX;i>fruitX-3;i--)
	{
		int j;
		for(j=fruitY;j>fruitY-3;j-- )
		{
			PCD8544_DrawPixel(i, j, PCD8544_Pixel_Set);
		}
	}
	PCD8544_DrawPixel(fruitX-1, fruitY-3, PCD8544_Pixel_Set);
}
void draw_score()
{

	char buffor[8];
	itoa(score,buffor,9);
	PCD8544_GotoXY(10,38);
	PCD8544_Puts("WYNIK: ",PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Puts(buffor ,PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

}

void draw()
{
	int i;
	for(i=lewa_sciana; i<=prawa_sciana; i++)
	{
		PCD8544_DrawPixel(i, gorna_sciana,PCD8544_Pixel_Set);
		PCD8544_DrawPixel(i, dolna_sciana,PCD8544_Pixel_Set);
	}

	for(i=gorna_sciana; i<=dolna_sciana; i++)
	{
		PCD8544_DrawPixel(lewa_sciana, i,PCD8544_Pixel_Set);
		PCD8544_DrawPixel(prawa_sciana, i,PCD8544_Pixel_Set);
	}
	draw_snake();
	draw_apple();

	draw_score();

	PCD8544_Refresh();

}


void setup()
{
	ntail=0;
	gameover = 0;
	dir = 1;
	head_x = 15;
	head_y = 15;
	fruitX = 22;
	fruitY = 22;
	score = 0;
}

int logic(int kierunek)
{
	dir=kierunek;
	switch (dir)
	{
	case 2:
		head_x--;
		break;
	case 1:
		head_x++;
		break;
	case 3:
		head_y--;
		break;
	case 4:
		head_y++;
	default:
		break;
	}
	int i;
	for(i=head_x;i>head_x-3;i--)
	{
		if (i >= prawa_sciana || i<= lewa_sciana)
				gameover = 1;
		int j;
		for(j=head_y;j>head_y-3;j-- )
		{
			if (j >= dolna_sciana || j <= gorna_sciana)
					gameover = 1;
			}
	}
	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == head_x&&tailY[i] == head_y)
			gameover = 1;
	}

	for(i=head_x;i>head_x-3;i--)
	{
		int j;
		for(j=head_y;j>head_y-3;j-- )
		{
			if(i==fruitX&&j==fruitY)
			{
				fruitX = (rand() % (prawa_sciana-8))+8;
				fruitY = (rand() % (dolna_sciana-8))+8;
				score+=1;
				ntail++;
			}
		}
	}
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = head_x;
	tailY[0] = head_y;
	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	if(gameover==1)
	{
		if(score>the_best)
		{
			the_best=score;
		}
		return 1;
	}
	else return 0;
}

