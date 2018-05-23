#include "stdafx.h"
#include "Jagody.h"
#include "Swiat.h"




Jagody::Jagody(int x, int y, Swiat* world)
	: Roslina(x, y, world)
{
	inicjatywa = 0;
	sila = 99;
}

Jagody::~Jagody()
{
}

Organizm * Jagody::Potomek()
{
	pustePoleObok();
	return new Jagody(newX, newY, swiat);
}

char Jagody::getSymbol()
{
	return 'J';
}

void Jagody::komunikujAtak()
{
	swiat->DodajKomunikat("Jagoda atakuje?! XD");
}

void Jagody::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("wilcza jagoda zwycieza");
}

void Jagody::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Wilcza jagoda ginie");
}

void Jagody::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Wilcza jagoda sie rozprzestrzenia");
}
