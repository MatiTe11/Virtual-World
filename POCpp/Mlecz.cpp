#include "stdafx.h"
#include "Mlecz.h"
#include "Swiat.h"


Mlecz::Mlecz(int x, int y, Swiat* world)
	: Roslina(x, y, world)
{
	sila = 0;
	inicjatywa = 0;
}


Mlecz::~Mlecz()
{
}

Organizm * Mlecz::Potomek()
{
	pustePoleObok();
	return new Mlecz(newX, newY, swiat);
}

char Mlecz::getSymbol()
{
	return 'm';
}

void Mlecz::komunikujAtak()
{
}

void Mlecz::komunikujZwyciestwo()
{
}

void Mlecz::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Mlecz zostal zjedzony");
}

void Mlecz::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Mlecz sie rozprzestrzenia");
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++)
	{
		int szansa = rand() % 6;

		if (szansa == 0 && czyPustePole())
		{
			komunikujRozmnazanie();
			swiat->DodajOrganizm(Potomek());
		}
	}
}
