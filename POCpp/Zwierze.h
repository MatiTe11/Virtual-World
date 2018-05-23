#pragma once
#include "Organizm.h"
#include "WynikWalki.h"
#include "Guarana.h"

#include <typeinfo>


class Zwierze :
	public Organizm
{
protected:
	int newX;
	int newY;

	void Ruch();
	

public:
	Zwierze(int x, int y, Swiat* world) ;
	~Zwierze();
	
	void zaatakuj(Organizm* wyzwany);
	void zwiekszSile();
	void moveToNew();
	// Inherited via Organizm
	virtual void akcja() override;
	virtual void kolizja(Organizm* poszkodowany) override;
	virtual void zjadlGuarane() override;
	WynikWalki obron(Organizm* agresor);
	
};



