#include "stdafx.h"
#include "Antylopa.h"
#include "Swiat.h"


Antylopa::Antylopa(int x, int y, Swiat* world)
	: Zwierze(x, y, world)
{
	inicjatywa = 4;
	sila = 4;
}


Antylopa::~Antylopa()
{
}

char Antylopa::getSymbol()
{
	return 'A';
}

Zwierze * Antylopa::Potomek()
{
	while (true)
	{
		Ruch();
		if (swiat->returnOrganizmXY(newX, newY) == nullptr)
			break;
	}
	Antylopa* a = new Antylopa(newX, newY, swiat);
	return a;
}

void Antylopa::akcja()
{
	if (wiek > 0)
	{
		Ruch();
		int prevX = x;
		int prevY = y;
		moveToNew();
		Ruch();
		x = prevX;
		y = prevY;
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

WynikWalki Antylopa::obron(Organizm * agresor)
{
	int czyUcieka = rand() % 2;
	if (czyUcieka == 0)
	{
		swiat->DodajKomunikat("Antylopa ucieka");
		if (czyPustePole())
		{
			while (true)
			{
				Ruch();
				if (swiat->returnOrganizmXY(newX, newY) == nullptr)
					break;
			}
			moveToNew();
		}
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

void Antylopa::komunikujAtak()
{
	swiat->DodajKomunikat("Antylopa atakuje");
}

void Antylopa::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Antylopa zwycieza");
}

void Antylopa::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Antylopa umiera");
}

void Antylopa::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Antylopa sie rozmnaza");
}

