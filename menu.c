#include"menu.h"

int a=0;
int b=10;

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

		int8_t c=0;
		// Odczyt akcelerometru
		if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update)) {
			c=akcelerometr_osx();
			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		}
		// Wskaznik do góry
		if(c<-10 && b!=10)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			c=0;
		}
		// Wska¿nik w dó³
		if(c>10&& b!=40)
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


			PCD8544_Clear();
			TIM_ClearFlag(TIM4, TIM_FLAG_Update);
		}
		draw();

	}

	PCD8544_Clear();
	PCD8544_Refresh();
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





