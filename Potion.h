#ifndef _POTION
#define _POTION
#include "main.h"
#include <iostream>

using namespace std;

class Potion
{
private:
	PotionType kindOfPotion;
	Potion *nextPotion;
public:
	Potion();
	Potion(PotionType);
	/*Potion(const Potion&);*/
	~Potion();
	void setNextPotion(Potion*);
	Potion* getNextPotion() const;
	PotionType GetType() const;
	friend ostream& operator<<(ostream&, const Potion&);
};
#endif
