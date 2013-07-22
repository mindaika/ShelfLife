#ifndef _POTION
#define _POTION
#include "main.h"
#include <iostream>

using namespace std;

class Potion
{
private:
	PotionType typeOfPotion;
public:
	Potion();
	Potion( PotionType );
	~Potion();
	PotionType GetType() const;
	friend ostream& operator<<( ostream&, const Potion& );
};
#endif
