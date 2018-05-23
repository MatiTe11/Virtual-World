#include "stdafx.h"
#include "Roslina.h"
#include "Swiat.h"


void Roslina::pustePoleObok()
{
	while (true)
	{
		int dir = rand() % 4;
		if (dir == 0) //up
		{
			if (y > 0 && swiat->returnOrganizmXY(x,y-1) == nullptr)
			{
				newX = x;
				newY = y - 1;
				break;
			}
		}
		else if (dir == 1) // right
		{
			if (x < wymiarX - 1 && swiat->returnOrganizmXY(x + 1, y) == nullptr)
			{
				newX = x + 1;
				newY = y;
				break;
			}
		}
		else if (dir == 2) //down
		{
			if (y < wymiarY - 1 && swiat->returnOrganizmXY(x, y + 1) == nullptr)
			{
				newX = x;
				newY = y + 1;
				break;
			}
		}
		else if (dir == 3) // left
		{
			if (x > 0 && swiat->returnOrganizmXY(x - 1, y) == nullptr)
			{
				newX = x - 1;
				newY = y;
				break;
			}
		}
	}
}

Roslina::Roslina(int x, int y, Swiat* world)
	: Organizm(x, y, world)
{
	srand(time(NULL));
}


Roslina::~Roslina()
{
}

void Roslina::akcja()
{
	int szansa = rand() % 6;

	if (szansa == 0 && czyPustePole())
	{
		komunikujRozmnazanie();
		swiat->DodajOrganizm(Potomek());
	}
}

void Roslina::kolizja(Organizm * poszkodowany)
{
}

void Roslina::zjadlGuarane()
{
}

WynikWalki Roslina::obron(Organizm * agresor)
{
	if (sila > agresor->getSila())
	{
		komunikujZwyciestwo();
		return wygrana;
	}
	else
	{
		komunikujPrzegrana();
		return przegrana;
	}
}

