// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "conio.h"
#include "iostream"
#include "string"
#define _USE_MATH_DEFINES
#include "math.h"

using namespace std;

int Menu()
{
	cout << "Make Your choice" << endl;
	cout << "" << endl;
	cout << "1. Type new lengths" << endl;
	cout << "2. Exit" << endl;

	int choice;
	cin >> choice;
	return choice;
}

int Perimeter(int, int, int);

double Area(double dA, double dB, double dC)
{
	double sPermimeter = (double)Perimeter(dA, dB, dC) / 2.0;
	return sqrt(sPermimeter*(sPermimeter - dA)*(sPermimeter - dB)*(sPermimeter - dC));
}

int Perimeter(int nA, int nB, int nC)
{
	return nA + nB + nC;
}

double AlphaAngle(double dA, double dB, double dC)
{
	double dAlphaAngle = (acos((pow(dB, 2) + pow(dC, 2) - pow(dA, 2)) / (2 * dB * dC))) * (180 / M_PI);
	return dAlphaAngle;
}

string TriangleName(double dA, double dB, double dC)
{
	string strTriangleName;
	if (pow(dA, 2) < pow(dB, 2) + pow(dC, 2) && pow(dB, 2) < pow(dA, 2) + pow(dC, 2) && pow(dC, 2) < pow(dB, 2) + pow(dA, 2))
		return strTriangleName = "acute";
	if (pow(dA, 2) == pow(dB, 2) + pow(dC, 2) || pow(dB, 2) == pow(dA, 2) + pow(dC, 2) || pow(dC, 2) == pow(dB, 2) + pow(dA, 2))
		return strTriangleName = "right";
	if (pow(dA, 2) > pow(dB, 2) + pow(dC, 2) || pow(dB, 2) > pow(dA, 2) + pow(dC, 2) || pow(dC, 2) > pow(dB, 2) + pow(dA, 2))
		return strTriangleName = "obtuse";
}

void Calculations()
{
	int nSideA;
	cout << "" << endl;
	cout << "Enter measurement of sides of the triangle" << endl;
	cout << "Side A: ";
	cin >> nSideA;

	int nSideB;
	cout << "Side B: ";
	cin >> nSideB;

	int nSideC;
	cout << "Side C: ";
	cin >> nSideC;

	if (nSideA + nSideB > nSideC && nSideA + nSideC > nSideB && nSideB + nSideC > nSideA)
	{
		cout << "" << endl;
		cout << "The Perimeter of the triangle is: " << Perimeter(nSideA, nSideB, nSideC) << endl;
		cout << "The Area of the triangle is: " << Area(nSideA, nSideB, nSideC) << endl;
		cout << "The Alpha angle is " << AlphaAngle(nSideA, nSideB, nSideC) << endl;
		cout << "For given lengths of sides in this case traingle is " << TriangleName(nSideA, nSideB, nSideC) << endl;
		cout << " " << endl;
	}
	else { cout << "It is impossible to create a triangle." << endl; }
}

void Loop()
{
	while (true)
	{
		int choice = Menu();
		switch (choice)
		{
		case 1:
			cout << "" << endl;
			Calculations();
			break;
		case 2:
			cout << "" << endl << "The End" << endl;
			return;
		default:
			cout << "" << "Unknown option" << endl;
		}
	}
}

void _tmain(int argc, _TCHAR* argv[])
{
	Loop();
}