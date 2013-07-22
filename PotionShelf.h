#ifndef _POTION_SHELF
#define _POTION_SHELF

#include "LinkedStack.h"
#include "Potion.h"

class PotionShelf : public LinkedStack<Potion>
{
private:
	int potionsOnShelf; // Shelf stock
	int shelfLimit;		// Shelf limit
public:
	// Makers and breakers
	PotionShelf(void);
	PotionShelf(int);
	~PotionShelf(void);

	bool push(const Potion&);
	bool pop();
};
#endif
