#pragma once
#include "Roslina.h"
class Barszcz :
	public Roslina
{
private:
	void atakuj(Organizm* wyzwany);
public:
	Barszcz(int x, int y, Swiat* world);
	~Barszcz();

	// Inherited via Roslina
	virtual Organizm * Potomek() override;
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
	virtual void akcja() override;
};

