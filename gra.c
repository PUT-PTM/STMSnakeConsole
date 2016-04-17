#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, dir1;
enum eDirection { STOP = 0, RIGHT, LEFT, UP, DOWN };
eDirection dir;

void setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y&&j == x)
			{
				cout << "O";
			}

			else if (i == fruitY&&j == fruitX)
				cout << "F";
			else
				cout << " ";

			if (j == width - 1)
				cout << "#";

		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "SCORE:" << score << endl;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}

void logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
	default:
		break;
	}

	if (x > width || x<0 || y>height || y < 0)
		gameover = true;

	if (x == fruitX && y == fruitY)
	{
		score = +10;
		fruitX = rand() % width;
		fruitY = rand() % height;

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setup();
	while (gameover != true)
	{
	
		draw();
		input();
		logic();
		Sleep(20);

	}
	return 0;
}

