#include"menu.h"

int a=0;
int b=10;
int c=0;
int kier=0;
int status_gry=0;
int os_x=0;
int os_y=0;
int the_best=0;

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
		PCD8544_Puts("    AUTORZY", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
		PCD8544_GotoXY(0,40);
		PCD8544_Puts("    ZAKONCZ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

		// WskaŸnik w menu

		PCD8544_GotoXY(0,b);
		PCD8544_Puts("-->", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);

		PCD8544_Refresh();


		// Wskaznik do góry
		if(kier==3 && b!=10)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			kier=0;
		}
		// Wska¿nik w dó³
		if(kier==4&& b!=40)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b+10;
			kier=0;
		}
		if(kier==1 && b==10)
		{
			gra();
			kier=0;
		}
		// Rekord
		if(kier==1 && b==20)
		{
		    rekord();
			kier=0;
		}
		// Opcje
    	if(kier==1 && b==30)
    	{

    	    PCD8544_Clear();
    	    PCD8544_Refresh();
    		opcje();
    		kier=0;
    	}
    	// Wyjscie
    	if(kier==1 && b==40)
    	{
    		PCD8544_Clear();
    		kier=0;
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
	while(status_gry==0)
	{
	}
	TIM_Cmd(TIM4, DISABLE);

	PCD8544_Clear();
	PCD8544_Refresh();
}

// Wywietlenie rekordu
void rekord()
{
	PCD8544_Clear();
	PCD8544_Refresh();
	char buffor[8];
	itoa(the_best,buffor,9);
	PCD8544_GotoXY(0, 20);
	PCD8544_Puts("TWOJ REKORD:", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Puts(buffor ,PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_Refresh();
	while(kier!=2)
	{
	}
	kier=0;
	PCD8544_Clear();
	PCD8544_Refresh();
}

//Zmiana ustawieñ
void opcje()
{
	PCD8544_Clear();
	PCD8544_Refresh();
	PCD8544_GotoXY(14, 5);
	PCD8544_Puts("SNAKE", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
	PCD8544_GotoXY(10, 19);
	PCD8544_Puts("Paulina Kurpisz", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_GotoXY(10, 32);
	PCD8544_Puts("Michal Suchorzynski", PCD8544_Pixel_Set, PCD8544_FontSize_3x5);
	PCD8544_Refresh();
	while(kier!=2)
	{
	}
	kier=0;
    PCD8544_Clear();
    PCD8544_Refresh();
}





