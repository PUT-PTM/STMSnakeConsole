#include"menu.h"

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
    int a=0;
    int b=0;
    // Oczekiwanie na przycisk
    while(a==0)
    {
    	a=przycisk(b);
    }
    PCD8544_Clear();
    PCD8544_Refresh();
    menu();
}
// G³owne menu
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
	int button=0;
	int x=0;
	while(x==0)
	{
		// WskaŸnik w menu
		PCD8544_GotoXY(0,b);
		PCD8544_Puts("-->", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
		PCD8544_Refresh();

		// Odczyt akcelerometru
		a=akcelerometr_osx();
		for(int i=0;i<30000000;i++){}

		// Wskaznik do góry
		if(a<-1 && b!=10)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b-10;
			a=0;
		}
		// Wska¿nik w dó³
		if(a>1&& b!=40)
		{
			PCD8544_GotoXY(0,b);
			PCD8544_Puts("   ", PCD8544_Pixel_Set, PCD8544_FontSize_5x7);
			b=b+10;
			a=0;
		}

		a=0;
		// Przejscie dalej
		a= przycisk(a);
		// Start
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
			x=1;
		}
	}
}

// Rozpoczecie gry
void gra(){}

// Wywietlenie rekordu
void rekord(){}

//Zmiana ustawieñ
void opcje(){}
