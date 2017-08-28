// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void setbuffersize()
{
	COORD c;
	c.X = 80;
	c.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void Size(int &size)
{
	int y = wherey();
	int i = y - 3;
	gotoxy(0,0);
	cout << "Select the size of the figure of range <5, " << i << "> Your choice is: ";
	while (true)
	{
		cin >> size;
		if (cin.fail())
		{
			cout << "This is not a number. Try again: ";
			cin.clear();
			cin.sync();
		}
		else
		{
			int j = wherey();
			if ((size > 4) && (size < 23 - j)) return;

			cout << "Bad range. Your choice must be between 5 to " << (24 - j - 3) << ". Try again: ";
			cin.clear();
			cin.sync();
		}
	}
	cout << endl;
}

void Sign(char &sign)
{
	cout << "Enter the sign what you want to draw a figure: ";
	cin >> sign;
	cout << endl;
}

void Legend()
{
	gotoxy(7, 24);
	cout << "+/- to zoom in/out" << "          ";
	cout << (char)(16) << " " << (char)(17) << " " << (char)(30) << " " << (char)(31) << " to move" << "          ";
	cout << "ESC to finish";
}

void Figure(int PositionX, int PositionY, int size, char sign)
{
	int k, l, y;
	y = wherey();

	gotoxy(PositionX, PositionY + y);

	for (k = 0; k < size; k++)
	{
		gotoxy(PositionX, PositionY + k);
		for (l = 0; l < size; l++)
		{
			if (l == 0 || k == size - 1 || l == size - 1 || k == size - 1 - l || (k == l && k < size / 2))
			cout << sign;
			else
				cout << " ";
		}
	}
}

void Control(int &PositionX, int &PositionY, int &size, char sign)
{
	char button;
	int i, j;
	i = wherey();
	j = 0;
	PositionY = i;
	PositionX = j;

	while (true)
	{
		Figure(PositionX, PositionY, size, sign);
		button = _getch();

		switch (button)
		{
		case 72: if (PositionY >= i) //Up
		{
					 Figure(PositionX, PositionY, size, ' ');
					 PositionY--;
		} break;
		case 80: if (PositionY + size <= 22)  //Down
		{
					 Figure(PositionX, PositionY, size, ' ');
					 PositionY++;
		} break;
		case 75: if (PositionX - 1 >= 0)  //Left
		{
					 Figure(PositionX, PositionY, size, ' ');
					 PositionX--;
		} break;
		case 77: if (PositionX + size <= 79)  //Right
		{
					 Figure(PositionX, PositionY, size, ' ');
					 PositionX++;
		} break;
		case 43: if (size <= 22 - PositionY && size + PositionX <= 79)
		{
					 Figure(PositionX, PositionY, size, ' ');
					 size++;
		} break;
		case 45: if (size > 5)
		{
					 Figure(PositionX, PositionY, size, ' ');
					 size--;
		} break;
		case 27: system("cls"); gotoxy(7, 7); cout << "The End" << endl; // escape
			_getch();
			return;
		default:
			break;
		}
	}
}

void main()
{
	int size, PositionY, PositionX;
	char sign;

	setbuffersize();
	Legend();
	Size(size);
	Sign(sign);
	Control(PositionY, PositionX, size, sign);
}