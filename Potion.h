#ifndef _POTION
#define _POTION

class Potion
{
private:
	//PotionType kindOfPotion;
public:
	Potion();
	~Potion();
	PotionType GetType();
	//ostream& operator<<(ostream&, const Potion&);
};
#include "Potion.cpp"
#endif
