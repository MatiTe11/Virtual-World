#include "stdafx.h"
#include "Barszcz.h"
#include "Swiat.h"
#include "Zwierze.h"


void Barszcz::atakuj(Organizm * wyzwany)
{
	if (wyzwany != nullptr)
	{
		try
		{
			//Zwierze* z = dynamic_cast<Zwierze*>(swiat->returnOrganizmXY(x + 1, y));
			Zwierze* z = dynamic_cast<Zwierze*>(wyzwany);
			if (z != nullptr)
			{
				komunikujAtak();
				WynikWalki wynik = z->obron(this);
				if (wynik == przegrana)
				{
					z->umrzyj();
				}
				else if (wynik == wygrana)
				{
					umrzyj();
				}
			}
			
		}
		catch (const std::exception& e)
		{

		}
	}
}

Barszcz::Barszcz(int x, int y, Swiat* world)
	: Roslina(x, y, world)
{
	inicjatywa = 0;
	sila = 99;
}

Barszcz::~Barszcz()
{
}

Organizm * Barszcz::Potomek()
{
	pustePoleObok();
	return new Barszcz(newX, newY, swiat);
}

char Barszcz::getSymbol()
{
	return 'B';
}

void Barszcz::komunikujAtak()
{
	swiat->DodajKomunikat("Barszcz atakuje");

}

void Barszcz::komunikujZwyciestwo()
{
	swiat->DodajKomunikat("Barszcz zabija");

}

void Barszcz::komunikujPrzegrana()
{
	swiat->DodajKomunikat("Barszcz umiera");

}

void Barszcz::komunikujRozmnazanie()
{
	swiat->DodajKomunikat("Barszcz sie rozprzestrzenia");

}

void Barszcz::akcja()
{
	int szansa = rand() % 6;

	if (szansa == 0 && czyPustePole())
	{
		komunikujRozmnazanie();
		swiat->DodajOrganizm(Potomek());
	}

	atakuj(swiat->returnOrganizmXY(x+1, y));
	atakuj(swiat->returnOrganizmXY(x-1, y));
	atakuj(swiat->returnOrganizmXY(x, y+1));
	atakuj(swiat->returnOrganizmXY(x, y-1));
}
