#include "stdafx.h"
#include "Wilk.h"
#include "Swiat.h"


Wilk::Wilk(int x, int y, Swiat* world) 
	: Zwierze(x,y,world)
{
	inicjatywa = 5;
	sila = 9;
}


Wilk::~Wilk()
{
}

char Wilk::getSymbol()
{
	return 'w';
}

Zwierze * Wilk::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Wilk* w = new Wilk(newX, newY, swiat);
	return w;
}

void Wilk::komunikujAtak()
{
	swiat->DodajKomunikat("Wilk atakuje");
}

void Wilk::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Wilk zwycieza");
}

void Wilk::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Wilk umiera");
}

void Wilk::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Wilk sie rozmnaza");
}
