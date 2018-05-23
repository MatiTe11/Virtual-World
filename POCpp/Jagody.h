#pragma once
#include "Roslina.h"
class Jagody :
	public Roslina
{
public:
	Jagody(int x, int y, Swiat* world);
	~Jagody();

	// Inherited via Roslina
	virtual Organizm * Potomek() override;
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
};

