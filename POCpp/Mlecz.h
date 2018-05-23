#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(int x, int y, Swiat* world);
	~Mlecz();

	// Inherited via Roslina
	virtual Organizm * Potomek() override;
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
	virtual void akcja() override;
};

