#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(int x, int y, Swiat* world);
	~Trawa();

	// Inherited via Roslina
	virtual Organizm * Potomek() override;
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
};

