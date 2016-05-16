// waz.cpp : Defines the entry point for the console application.
///*
/*
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, dir1, ntail;
int tailX[100], tailY[100];
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
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j &&tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

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

	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == x&&tailY[i] == y)
			gameover = true;
	}

	if (x == fruitX && y == fruitY)
	{
		score = +10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
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
		Sleep(30);

	}
	return 0;
}

*/
