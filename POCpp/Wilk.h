#pragma once
#include "Zwierze.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(int x, int y, Swiat* world);
	~Wilk();

	// Inherited via Zwierze
	virtual char getSymbol() override;
	virtual Zwierze * Potomek() override;

	// Inherited via Zwierze
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
};

