#ifndef _POTION
#define _POTION
#include "main.h"
#include <iostream>

class Potion
{
private:
	PotionType typeOfPotion;
public:
	Potion();
	Potion( PotionType );
	virtual ~Potion(void);
	PotionType GetType() const;
	friend std::ostream& operator<<( std::ostream&, const Potion& );
};
#endif
