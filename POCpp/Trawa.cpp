#include "stdafx.h"
#include "Trawa.h"
#include "Swiat.h"



Trawa::Trawa(int x, int y, Swiat* world)
	: Roslina(x, y, world)
{
	inicjatywa = 0;
	sila = 0;
}


Trawa::~Trawa()
{
}

Organizm * Trawa::Potomek()
{
	pustePoleObok();
	return new Trawa(newX, newY, swiat);
}

char Trawa::getSymbol()
{
	return 't';
}

void Trawa::komunikujAtak()
{
	swiat->DodajKomunikat("Trawa atakuje?! XD");
}

void Trawa::komunikujZwyciestwo()
{
}

void Trawa::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Trawa zostala zjedzona");
}

void Trawa::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Trawa sie rozprzestrzenia");
}
