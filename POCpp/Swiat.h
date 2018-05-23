#pragma once
#include "Organizm.h"
#include <vector>
#include <string>
#include "CzlowiekStan.h"

class Czlowiek;
 
class Swiat
{
private:
	int wymiarX, wymiarY;
	std::vector<Organizm*> organizmy;
	std::vector<std::string> wiadomosci;
	char** map;
	CzlowiekStan stan;

	void swapPoint(Organizm* &one, Organizm* &two);
	void Sort(int l, int p);
	void StworzSwiat();
	void ZerujMape();
	void UzupelnijMape();
	void cleanOrganizmy();

public:
	Swiat(int wymiarX, int wymiarY);
	int getWymiarX();
	int getWymiarY();
	CzlowiekStan getStan();
	Organizm* returnOrganizmXY(int x, int y);
	void wykonajTure(CzlowiekStan stan);
	void rysuj();
	void wypiszKomunikaty();
	void DodajOrganizm(Organizm* nowyOrg);
	void ZabijOrganizm(Organizm* doUsunieca);
	void DodajKomunikat(std::string msg);
	~Swiat();
};

