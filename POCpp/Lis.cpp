#include "stdafx.h"
#include "Lis.h"
#include "Swiat.h"



Lis::Lis(int x, int y, Swiat* world)
	: Zwierze(x, y, world)
{
	sila = 3;
	inicjatywa = 7;
}


Lis::~Lis()
{
}

char Lis::getSymbol()
{
	return 'L';
}

Zwierze * Lis::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Lis* l = new Lis(newX, newY, swiat);
	return l;
}

void Lis::akcja()
{
	if (wiek > 0)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) != nullptr)
		{
			if(swiat->returnOrganizmXY(newX, newY)->getSila() <= sila)
				kolizja(swiat->returnOrganizmXY(newX, newY));
		}
		else
		{
			moveToNew();
		}
	}
	wiek++;
}

void Lis::komunikujAtak()
{
	swiat->DodajKomunikat("Lis atakuje");
}

void Lis::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Lis zwycieza");
}

void Lis::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Lis umiera");
}

void Lis::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Lis sie rozmnaza");
}
