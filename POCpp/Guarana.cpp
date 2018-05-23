#include "stdafx.h"
#include "Guarana.h"
#include "Swiat.h"


Guarana::Guarana(int x, int y, Swiat* world)
	: Roslina(x, y, world)
{
	inicjatywa = 0;
	sila = 0;
}


Guarana::~Guarana()
{
}

Organizm * Guarana::Potomek()
{
	pustePoleObok();
	return new Guarana(newX, newY, swiat);
}

char Guarana::getSymbol()
{
	return 'G';
}

void Guarana::komunikujAtak()
{
	swiat->DodajKomunikat("Guarana atakuje?! XD");
}

void Guarana::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Guarana zwycieza");

}

void Guarana::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Guarana zostaje zjedzona");

}

void Guarana::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Guarana sie rozprzestrzenia");

}

WynikWalki Guarana::obron(Organizm * agresor)
{
	if (sila > agresor->getSila())
	{
		komunikujZwyciestwo();
		return wygrana;
	}
	else
	{
		agresor->zjadlGuarane();
		komunikujPrzegrana();
		return przegrana;
	}
}
