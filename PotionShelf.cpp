#include "PotionShelf.h"

// Default constructor
PotionShelf::PotionShelf(void)
{
	shelfLimit = 10;
	potionsOnShelf = 0;
}

// Parameterized constructor
PotionShelf::PotionShelf(int limit)
{
	shelfLimit = limit;
	potionsOnShelf = 0;
}

// Overrides base push to test for shelf limits
bool PotionShelf::push(const Potion& potion)
{
	bool successful = false;
	if ( potionsOnShelf < shelfLimit ) {
		LinkedStack::push(potion);
		successful = true;
		potionsOnShelf++;
	}
	return successful;	
}

// Overrides base pop to allow for shelf operation
bool PotionShelf::pop() 
{
	bool successful = false;
	if( LinkedStack::pop() ) {
		potionsOnShelf--;
		successful = true;
	}
	return successful;
}

// Destructor!
PotionShelf::~PotionShelf(void)
{
}
