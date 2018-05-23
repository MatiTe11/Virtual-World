#pragma once
#include "Zwierze.h"
#include "CzlowiekStan.h"
class Czlowiek :
	public Zwierze
{
private:
	int umiejetnoscTura;
	void przyjmijRozkaz(CzlowiekStan stan);
public:
	Czlowiek(int x, int y, Swiat* world);
	~Czlowiek();

	// Inherited via Zwierze
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
	virtual Zwierze * Potomek() override;
	virtual void akcja() override;
	WynikWalki obron(Organizm* agresor) override;
	
};

