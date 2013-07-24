#include <iostream>
#include "Apothecary.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

// MODIFIED FROM SOURCE

char* PotionTypeString(PotionType type)
{
	char* s = "";

	switch (type) {
	case SPEED:
		s =  "Speed";
		break;
	case STRENGTH:
		s =  "Strength";
		break;
	case HEALTH:
		s = "Health";
		break;
	case WISDOM:
		s = "Wisdom";
		break;
	}
	return(s);
}


void BuyPotion(Apothecary& apo)
{
	Potion potion;
	if (apo.BuyPotion(potion)) {
		std::cout << "Congratulations! You just bought a " << PotionTypeString(potion.GetType()) << " potion!" << std::endl;
		std::cout << potion;
	} else {
		std::cout << "There were no potions available." << std::endl;
	}
}

void OrderPotion(Apothecary& apo,PotionType type)
{
	bool ret = apo.OrderPotion(type);
	if (ret) {
		std::cout << "Your potion (" << PotionTypeString(type) << ") has been added to the queue!" << std::endl;
	} else {
		std::cout << "The order queue is full." << std::endl;
	}

}

void MakePotions(Apothecary& apo)
{
	std::cout << "About to try to make some potions." << std::endl;
	int count = apo.MakePotions();
	std::cout << "Made " << count << " potions." << std::endl;
}

void TestApothecary()
{
	Apothecary apo(5,20);  // order limit, shelf limit
	
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);
	
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,HEALTH);

	BuyPotion(apo);
	BuyPotion(apo);
	BuyPotion(apo);
	BuyPotion(apo);

	MakePotions(apo);

	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);

	BuyPotion(apo);
	
	MakePotions(apo);

}

int main() {

	TestApothecary();

#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "Memory leaks!" << std::endl;
	}
#endif

	std::cout << "Press Return to exit...";
	getchar();
	return 0;
}
