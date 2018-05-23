#pragma once
#include "WynikWalki.h"
#include <cstdlib>
#include <ctime>

class Swiat;

class Organizm
{

protected:
	int sila;
	int inicjatywa;
	int wiek;
	int x;
	int y;
	int wymiarX;
	int wymiarY;
	Swiat* swiat;
	bool czyPustePole();
	virtual Organizm* Potomek() = 0;
	bool dead;

public:
	Organizm(int x, int y, Swiat* world);
	int getWiek();
	int getInicjatywa();
	int getSila();
	int getX();
	int getY();
	bool isAlive();
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* poszkodowany) = 0;
	virtual WynikWalki obron(Organizm* agresor) = 0;
	virtual char getSymbol() = 0;
	virtual void komunikujAtak() = 0;
	virtual void komunikujZwyciestwo() = 0;
	virtual void komunikujPrzegrana() = 0;
	virtual void komunikujRozmnazanie() = 0;
	virtual void zjadlGuarane() = 0;
	void umrzyj();
	~Organizm();

	
};


