#include "stdafx.h"
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "CzlowiekStan.h"
#include "Czlowiek.h"
#include "Trawa.h"
#include "Jagody.h"
#include "Guarana.h"
#include "Barszcz.h"
#include "Mlecz.h"
#include "Organizm.h"
#include <iostream>

void Swiat::swapPoint(Organizm* &one, Organizm* &two)
{
	Organizm* t = two;
	two = one;
	one = t;
}

bool isSmaller(Organizm* num, Organizm* than)
{
	if (num == nullptr)
		return true;
	if (than == nullptr)
		return false;
	if (num->getInicjatywa() < than->getInicjatywa())
		return true;
	else if (num->getInicjatywa() == than->getInicjatywa())
	{
		if (num->getWiek() < than->getWiek())
			return true;
	}
	return false;
}


void Swiat::Sort(int l, int p)
{
	////
	int i, j;

	int index = (l + p) / 2;
	Organizm* pivot = organizmy[index];
	

	//swap(liczby[(l + p) / 2], liczby[p]);
	pivot = organizmy[(l + p) / 2]; 
	organizmy[(l + p) / 2] = organizmy[p];
	for (i = j = l; i < p; i++)
	{
		if (isSmaller(organizmy[i], pivot))
		{
			swapPoint(organizmy[i], organizmy[j]);
			j++;
			//wypisz();
		}
	}
	//swap(liczby[(l + p) / 2], liczby[p]);
	//next rek
	organizmy[p] = organizmy[j];
	organizmy[j] = pivot;

	if (l < j - 1)  Sort(l, j - 1);
	if (j + 1 < p) Sort(j + 1, p);
}

void Swiat::StworzSwiat()
{
	Wilk* w = new Wilk(0, 0, this);
	DodajOrganizm(w);
	w = new Wilk(1, 10, this);
	DodajOrganizm(w);
	Owca* o = new Owca(5, 4, this);
	DodajOrganizm(o);
	o = new Owca(8, 3, this);
	DodajOrganizm(o);
	DodajOrganizm(new Lis(7, 7, this));
	DodajOrganizm(new Zolw(12, 5, this));
	DodajOrganizm(new Lis(4, 7, this));
	DodajOrganizm(new Zolw(8, 5, this));
	DodajOrganizm(new Antylopa(13, 7, this));
	DodajOrganizm(new Antylopa(14, 5, this));
	DodajOrganizm(new Antylopa(0, 5, this));
	DodajOrganizm(new Czlowiek(10, 15, this));
	DodajOrganizm(new Trawa(2, 2, this));
	DodajOrganizm(new Mlecz(19, 19, this));
	DodajOrganizm(new Jagody(8, 0, this));
	DodajOrganizm(new Barszcz(8, 15, this));
	DodajOrganizm(new Guarana(8, 17, this));

}

void Swiat::ZerujMape()
{
	for (int i = 0; i < wymiarY; i++)
	{
		for (int j = 0; j < wymiarX; j++)
		{
			map[j][i] = '.';
		}
	}
}

void Swiat::UzupelnijMape()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i] != nullptr)
		{
			int x = organizmy[i]->getX();
			int y = organizmy[i]->getY();
			map[x][y] = organizmy[i]->getSymbol();
		}
	}
}

void Swiat::cleanOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i] == nullptr)
		{
			organizmy.erase(organizmy.begin() + i);
			i--;
		}
	}
}

Swiat::Swiat(int wymiarX, int wymiarY)
{
	this->wymiarX = wymiarX;
	this->wymiarY = wymiarY;
	map = new char*[wymiarX];
	for (int i = 0; i < wymiarX; i++)
	{
		map[i] = new char[wymiarY];
	}
	stan = rest;

	StworzSwiat();
}

int Swiat::getWymiarX()
{
	return wymiarX;
}

int Swiat::getWymiarY()
{
	return wymiarY;
}

CzlowiekStan Swiat::getStan()
{
	return stan;
}

Organizm * Swiat::returnOrganizmXY(int x, int y)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i] != nullptr)
		{
			if (organizmy[i]->getX() == x && organizmy[i]->getY() == y)
			{
				return organizmy[i];
			}
		}
	}
	return nullptr;
}


void Swiat::wykonajTure(CzlowiekStan stan)
{
	this->stan = stan;
	wiadomosci.clear();
	Sort(0, organizmy.size() - 1);
	ZerujMape();
	for (int i = organizmy.size() - 1; i >=0; i--)
	{
		if(organizmy[i] != nullptr)
			organizmy[i]->akcja();
	}
	//ZabijOrganizmy();
	cleanOrganizmy();
	UzupelnijMape();
}

void Swiat::rysuj()
{
	for (int i = 0; i < wymiarY; i++)
	{
		for (int j = 0; j < wymiarX; j++)
		{
			std::cout << map[j][i];
		}
		std::cout << std::endl;
	}
}

void Swiat::wypiszKomunikaty()
{
	for (int i = 0; i < wiadomosci.size(); i++)
	{
		std::cout << wiadomosci[i] << std::endl;
	}
}

void Swiat::DodajOrganizm(Organizm * nowyOrg)
{
	organizmy.push_back(nowyOrg);
}

void Swiat::ZabijOrganizm(Organizm * doUsunieca)
{
	int iterator = -1;
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i] == doUsunieca)
			iterator = i;
	}
	if (iterator != -1)
	{
		delete organizmy[iterator];
		organizmy[iterator] = nullptr;
	}
	
}

void Swiat::DodajKomunikat(std::string msg)
{
	wiadomosci.push_back(msg);
}

Swiat::~Swiat()
{
}
