#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
protected:
	int newX, newY;
	void pustePoleObok();
public:
	Roslina(int x, int y, Swiat* world);
	~Roslina();

	// Inherited via Organizm
	virtual void akcja() override;
	virtual void kolizja(Organizm * poszkodowany) override;
	virtual void zjadlGuarane() override;
	virtual WynikWalki obron(Organizm * agresor) override;

};

