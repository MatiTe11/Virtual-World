#include "stdafx.h"
#include "Owca.h"
#include "Swiat.h"



Owca::Owca(int x, int y, Swiat* world)
	: Zwierze(x, y, world)
{
	sila = 4;
	inicjatywa = 4;
}


Owca::~Owca()
{
}

char Owca::getSymbol()
{
	return 'o';
}

Zwierze * Owca::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Owca* o = new Owca(newX, newY, swiat);
	return o;
}

void Owca::komunikujAtak()
{
	swiat->DodajKomunikat("Owca atakuje");
}

void Owca::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Owca zwycieza");
}

void Owca::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Owca umiera");
}

void Owca::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Owca sie rozmnaza");
}
