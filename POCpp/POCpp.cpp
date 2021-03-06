// POCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Swiat.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "CzlowiekStan.h"

using namespace std;

int main()
{
	char a;
	Swiat ziemia(20, 20);
	CzlowiekStan stan;
	bool correctInput;

	while (true)
	{
		correctInput = true;
		a = _getch();
		switch (a)
		{
		case 'a': stan = CzlowiekStan::left;
			break;
		case 's': stan = down;
			break;
		case 'd': stan = CzlowiekStan::right;
			break;
		case 'w': stan = up;
			break;
		case 'r': stan = activate;
			break;
		case 13: stan = rest;
			break;
		default: correctInput = false;
			break;
		}

		if (correctInput)
		{
			ziemia.wykonajTure(stan);
			system("cls");
			cout << "Autor: Mateusz Tegowski 165770" << endl;
			ziemia.rysuj();
			cout << endl;
			ziemia.wypiszKomunikaty();
		}
	}
    return 0;
}

