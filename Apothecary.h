#pragma once
#include "Potion.h"
class Apothecary
{
public:
	Apothecary(void);
	~Apothecary(void);
	bool BuyPotion(Potion& potion);
	bool OrderPotion(PotionType);
	int MakePotions();
};

