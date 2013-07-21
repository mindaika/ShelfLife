#include "Potion.h"

// Default constructor
// Creates a mystery potion
Potion::Potion()
{
	kindOfPotion = UNKNOWN;
	nextPotion = nullptr;
}

// Parameterized constructor
// Creates a specified type of potion
Potion::Potion(PotionType potion)
{
	kindOfPotion = potion;
	nextPotion = nullptr;
}
//
//// Copy constructor
//Potion::Potion(const Potion& potion)
//{
//
//}

// Default destructor
Potion::~Potion(void)
{
	nextPotion = nullptr;
}

// Overloads << to return a potion
ostream& operator<<(ostream& os, const Potion& potion)
{
	os << "Potion of " << PotionTypeString(potion.GetType()) << endl;
	return os;
}

// Sets the pointer to the next potion in the stack
void Potion::setNextPotion(Potion* potion)
{
	nextPotion = potion;
}

// Returns type of potion
PotionType Potion::GetType() const
{
	return kindOfPotion;
}

Potion* Potion::getNextPotion() const
{
	return nextPotion;
}

