#pragma once
#include "Roslina.h"
#include "Zwierze.h"
class Guarana :
	public Roslina
{
public:
	Guarana(int x, int y, Swiat* world);
	~Guarana();

	// Inherited via Roslina
	virtual Organizm * Potomek() override;
	virtual char getSymbol() override;
	virtual void komunikujAtak() override;
	virtual void komunikujZwyciestwo() override;
	virtual void komunikujPrzegrana() override;
	virtual void komunikujRozmnazanie() override;
	virtual WynikWalki obron(Organizm * agresor) override;
};

