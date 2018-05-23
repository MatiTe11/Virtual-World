#include "stdafx.h"
#include "Czlowiek.h"
#include "Swiat.h"


Czlowiek::Czlowiek(int x, int y, Swiat* world)
	: Zwierze(x, y, world)
{
	umiejetnoscTura = 0;
	inicjatywa = 4;
	sila = 5;
	
}


Czlowiek::~Czlowiek()
{
}

char Czlowiek::getSymbol()
{
	return '&';
}

void Czlowiek::komunikujAtak()
{
	swiat->DodajKomunikat("Czlowiek atakuje");
}

void Czlowiek::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Czlowiek wygrywa");

}

void Czlowiek::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Czlowiek ginie");
}

void Czlowiek::komunikujRozmnazanie()
{
}

Zwierze * Czlowiek::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Czlowiek* a = new Czlowiek(newX, newY, swiat);
	return a;
}

void Czlowiek::akcja()
{
	przyjmijRozkaz(swiat->getStan());
	if (!(newX == x && newY == y)  && swiat->returnOrganizmXY(newX, newY) != nullptr)
	{
		kolizja(swiat->returnOrganizmXY(newX, newY));
	}
	else
	{
		moveToNew();
	}
	wiek++;
	umiejetnoscTura--;
}

WynikWalki Czlowiek::obron(Organizm * agresor)
{
	if (umiejetnoscTura >= 6)
	{
		swiat->DodajKomunikat("Czlowiek uzywa niesmiertelnosci");
		if (czyPustePole())
		{
			while (true)
			{
				Ruch();
				if (swiat->returnOrganizmXY(newX, newY) == nullptr)
					break;
			}
			moveToNew();
			return niesmiertelnosc;
		}
		else
		{
			return remis;
		}
	}
	else if (sila > agresor->getSila())
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

void Czlowiek::przyjmijRozkaz(CzlowiekStan stan)
{
	switch (stan)
	{
	case up:
		if (y > 0)
		{
			newX = x;
			newY = y - 1;
		}
		break;
	case down:
		if (y < wymiarY - 1)
		{
			newX = x;
			newY = y + 1;
		}
		break;
	case right:
		if (x < wymiarX - 1)
		{
			newX = x + 1;
			newY = y;
		}
		break;
	case left:
		if (x > 0)
		{
			newX = x - 1;
			newY = y;
		}
		break;
	case rest:
		newX = x;
		newY = y;
		break;
	case activate: 
		if (umiejetnoscTura <= 0)
		{
			swiat->DodajKomunikat("Czlowiek uruchamia niesmiertelnosc");
			umiejetnoscTura = 10;
			newX = x;
			newY = y;
		}
		else
		{
			swiat->DodajKomunikat("Nie mozesz uruchomic niesmiertelnosci w tym momencie");
		}
	default:
		break;
	}
}
