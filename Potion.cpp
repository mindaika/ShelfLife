#include "Potion.h"



// Default constructor
// Creates a mystery potion
Potion::Potion()
{
	typeOfPotion = UNKNOWN;
}

// Parameterized constructor
// Creates a specified type of potion
Potion::Potion(PotionType potion)
{
	typeOfPotion = potion;
}

// Default destructor
Potion::~Potion(void)
{
}

// Overloads << to return a potion
std::ostream& operator<<(std::ostream& os, const Potion& potion)
{
	os << "Potion of " << PotionTypeString( potion.GetType() ) << std::endl;
	return os;
}

// Returns type of potion
PotionType Potion::GetType() const
{
	return typeOfPotion;
}