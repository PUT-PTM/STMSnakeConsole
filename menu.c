#include"menu.h"

<<<<<<< HEAD
int a=0;
int b=10;

=======


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




>>>>>>> origin/master
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
// G³owne menu
void menu()
{
	TIM_Cmd(TIM2, ENABLE);
<<<<<<< HEAD

=======
	PCD8544_GotoXY(0,10);
	PCD8544_Puts("    START", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,20);
	PCD8544_Puts("    REKORD", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,30);
	PCD8544_Puts("    OPCJE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(0,40);
	PCD8544_Puts("    ZAKONCZ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Refresh();
>>>>>>> origin/master
	while(1)
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
		// WskaŸnik w menu
		PCD8544_GotoXY(0,b);
		PCD8544_Puts("-->", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
		PCD8544_Refresh();

<<<<<<< HEAD
		int8_t c=0;
=======
		int c=0;
>>>>>>> origin/master
		// Odczyt akcelerometru
		if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)) {
			c=akcelerometr_osx();
			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		}
		// Wskaznik do góry
<<<<<<< HEAD
		if(c<-10 && b!=10)
=======
		if(c<-30 && b!=10)
>>>>>>> origin/master
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			c=0;
		}
		// Wska¿nik w dó³
<<<<<<< HEAD
		if(c>10&& b!=40)
=======
		if(c>30&& b!=40)
>>>>>>> origin/master
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
<<<<<<< HEAD
	PCD8544_Clear();
	TIM_Cmd(TIM3, DISABLE);
	TIM_Cmd(TIM4, ENABLE);
	setup();
	int status_gry=0;
	int os_x=0;
	int os_y=0;
	int kier=0;
	while(status_gry==0)
	{
		if(TIM_GetFlagStatus(TIM4, TIM_FLAG_Update))
		{
			os_x=akcelerometr_osx();
			os_y=akcelerometr_osy();
			if(os_x<-10)
			{
				kier=2;
				os_y=0;

			}
			if(os_x>10)
			{
				kier=1;
				os_y=0;
			}
			if(os_y<-10)
			{
				kier=4;
				os_x=0;
			}
			if(os_y>10)
			{
				kier=3;
				os_x=0;
			}
			status_gry=logic(kier);


			TIM_ClearFlag(TIM4, TIM_FLAG_Update);
		}
		draw();

	}

	PCD8544_Clear();
	PCD8544_Refresh();
=======
	setup();
	draw();
>>>>>>> origin/master
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

//Zmiana ustawieñ
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
<<<<<<< HEAD




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

=======
>>>>>>> origin/master
