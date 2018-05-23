#pragma once
#include "Zwierze.h"

class Zolw :
	public Zwierze
{
public:
	Zolw(int x, int y, Swiat* world);
	~Zolw();

	// Inherited via Zwierze
	virtual char getSymbol() override;
	virtual Zwierze * Potomek() override;
	virtual void akcja() override;
	WynikWalki obron(Organizm* agresor) override;

	// Inherited via Zwierze
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
};

