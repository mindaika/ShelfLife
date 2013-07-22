#ifndef _POTION_SHELF
#define _POTION_SHELF

#include "LinkedStack.h"
#include "Potion.h"

// PotionShelf manages a Stack of potions
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
	
	// Overrides
	bool push(const Potion&);
	bool pop();

	// Test to see if shelf is full
	bool isFull();
};
#endif
