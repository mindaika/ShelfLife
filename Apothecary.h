#ifndef _APO
#define _APO
#include "Potion.h"
#include "main.h"

class Apothecary
{
public:
	Apothecary(int, int);
	~Apothecary();
	bool BuyPotion(Potion&);
	bool OrderPotion(PotionType);
	int MakePotions();
};
#include "Apothecary.cpp"
#endif