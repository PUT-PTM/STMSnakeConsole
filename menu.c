#include"menu.h"



int a=0;
int b=10;


void EXTI1_IRQHandler(void)
{
	TIM_Cmd(TIM3, ENABLE);
}
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
		if(EXTI_GetITStatus(EXTI_Line1) != RESET)
		{
		    a=1;
		    EXTI_ClearITPendingBit(EXTI_Line1);
	   }
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		TIM_Cmd(TIM3, DISABLE);
		TIM_SetCounter(TIM3, 0);
    }
}




// Ekran Startowy
void start()
{
	PCD8544_GotoXY(14, 3);
    PCD8544_Puts("SNAKE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
    PCD8544_GotoXY(10, 14);
    PCD8544_Puts("Paulina Kurpisz", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(10, 27);
	PCD8544_Puts("Michal Suchorzynski", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
    PCD8544_Refresh();
     // Oczekiwanie na przycisk
    while(a==0)
    {}
    a=0;
    PCD8544_Clear();
    PCD8544_Refresh();
    menu();
}
// G�owne menu
void menu()
{
	TIM_Cmd(TIM2, ENABLE);
	PCD8544_GotoXY(0,10);
	PCD8544_Puts("    START", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,20);
	PCD8544_Puts("    REKORD", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,30);
	PCD8544_Puts("    OPCJE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,40);
	PCD8544_Puts("    ZAKONCZ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Refresh();
	while(1)
	{
		// Wska�nik w menu
		PCD8544_GotoXY(0,b);
		PCD8544_Puts("-->", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
		PCD8544_Refresh();

		int c=0;
		// Odczyt akcelerometru
		if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)) {
			c=akcelerometr_osx();
			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		}
		// Wskaznik do g�ry
		if(c<-30 && b!=10)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			c=0;
		}
		// Wska�nik w d�
		if(c>30&& b!=40)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b+10;
			c=0;
		}
		if(a==1 && b==10)
		{
			gra();
		    a=0;
		}
		// Rekord
		if(a==1 && b==20)
		{
			rekord();
		    a=0;
		}
		// Opcje
    	if(a==1 && b==30)
    	{
    		opcje();
    		a=0;
    	}
    	// Wyjscie
    	if(a==1 && b==40)
    	{
    		PCD8544_Clear();
    		a=0;
    		return;
		}

	}
}

// Rozpoczecie gry
void gra(){
	setup();
	draw();
}

// Wywietlenie rekordu
void rekord()
{
	PCD8544_Clear();
	PCD8544_GotoXY(10, 14);
	PCD8544_Puts("Twoj najlepszy wynik: ", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_Refresh();
	while(a==0)
	{
	}
	a=0;
}

//Zmiana ustawie�
void opcje()
{
	PCD8544_Clear();
	PCD8544_GotoXY(3, 5);
	PCD8544_Puts("Zmien poziom trudnosci: ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Refresh();
	while(a==0)
	{
	}
	a=0;
}
