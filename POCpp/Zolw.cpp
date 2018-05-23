#include "stdafx.h"
#include "Zolw.h"
# include "Swiat.h"



Zolw::Zolw(int x, int y, Swiat* world)
	: Zwierze(x, y, world)
{
	inicjatywa = 2;
	sila = 1;
}


Zolw::~Zolw()
{
}

char Zolw::getSymbol()
{
	return 'z';
}

Zwierze * Zolw::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Zolw* z = new Zolw(newX, newY, swiat);
	return z;
}

void Zolw::akcja()
{
	int czyRuch = rand() % 4;
	if (czyRuch == 0)
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
	}
	wiek++;
}

WynikWalki Zolw::obron(Organizm * agresor)
{
	if (agresor->getSila() < 5)
	{
		swiat->DodajKomunikat("Zolw odpiera atak");
		return remis;
	}
	else
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
}

void Zolw::komunikujAtak()
{
	swiat->DodajKomunikat("Zolw atakuje");
}

void Zolw::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Zolw zwycieza");
}

void Zolw::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Zolw umiera");
}

void Zolw::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Zolw sie rozmnaza");
}
