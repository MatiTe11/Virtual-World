#include "stdafx.h"
#include "Organizm.h"
#include "Swiat.h"



bool Organizm::czyPustePole()
{
	if ((x > 0 && swiat->returnOrganizmXY(x - 1, y) == nullptr) || (y > 0 && swiat->returnOrganizmXY(x, y - 1) == nullptr)
		|| (x < wymiarX - 1 && swiat->returnOrganizmXY(x + 1, y) == nullptr) || (y < wymiarY - 1 && swiat->returnOrganizmXY(x, y + 1) == nullptr))
		return true;
	else
		return false;
}

Organizm::Organizm(int x, int y, Swiat* world)
{
	dead = false;
	this->x = x;
	this->y = y;
	swiat = world;
	wymiarX = swiat->getWymiarX();
	wymiarY = swiat->getWymiarY();
	wiek = 0;
	srand(time(NULL));
}

int Organizm::getWiek()
{
	return wiek;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

int Organizm::getSila()
{
	return sila;
}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}

bool Organizm::isAlive()
{
	return !dead;
}


void Organizm::umrzyj()
{
	//dead = true;
	swiat->ZabijOrganizm(swiat->returnOrganizmXY(x, y));
}

Organizm::~Organizm()
{
}
