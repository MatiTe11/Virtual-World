#include "stdafx.h"
#include "Zwierze.h"
#include "Swiat.h"
#include <string>



void Zwierze::Ruch()
{
	while (true)
	{
		int dir = rand() % 4;
		if (dir == 0) //up
		{
			if (y > 0)
			{
				newX = x;
				newY = y-1;
				break;
			}
		}
		else if (dir == 1) // right
		{
			if (x < wymiarX - 1)
			{
				newX = x+1;
				newY = y;
				break;
			}
		}
		else if (dir == 2) //down
		{
			if (y < wymiarY - 1)
			{
				newX = x;
				newY = y+1;
				break;
			}
		}
		else if (dir == 3) // left
		{
			if (x > 0)
			{
				newX = x-1;
				newY = y;
				break;
			}
		}
	}
}

Zwierze::Zwierze(int x, int y, Swiat* world) 
	: Organizm(x, y, world)
{
	
}


Zwierze::~Zwierze()
{
}

void Zwierze::akcja()
{
	if (wiek > 0)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) != nullptr)
		{
			kolizja(swiat->returnOrganizmXY(newX, newY));
		}
		else
		{
			moveToNew();
		}
	}
	wiek++;
}

void Zwierze::kolizja(Organizm* poszkodowany)
{
	
	if (poszkodowany->getSymbol() == this->getSymbol())
	{
		if (czyPustePole())
		{
			komunikujRozmnazanie();
			swiat->DodajOrganizm(Potomek());
		}
	}
	else
	{
		zaatakuj(poszkodowany);
	}
}

void Zwierze::zjadlGuarane()
{
	sila += 3;
}

void Zwierze::zaatakuj(Organizm* wyzwany)
{
	komunikujAtak();
	WynikWalki wynik = wyzwany->obron(this);
	if (wynik == przegrana)
	{
		wyzwany->umrzyj();
		moveToNew();
	}
	else if (wynik == wygrana)
	{
		umrzyj();
	}
	else if (wynik == niesmiertelnosc)
	{
		moveToNew();
	}
}

void Zwierze::zwiekszSile()
{
	sila += 3;
}

WynikWalki Zwierze::obron(Organizm * agresor)
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

void Zwierze::moveToNew()
{
	x = newX;
	y = newY;
}


