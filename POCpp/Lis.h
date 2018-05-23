#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(int x, int y, Swiat* world);
	~Lis();

	// Inherited via Zwierze
	virtual char getSymbol() override;
	virtual Zwierze * Potomek() override;
	virtual void akcja() override;

	// Inherited via Zwierze
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
};

