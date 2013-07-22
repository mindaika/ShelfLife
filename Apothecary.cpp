#include "Apothecary.h"

// Default Constuctor
Apothecary::Apothecary()
{
	potionShelf = new PotionShelf();
	orderList = new OrderQueue();
}


// Constructor
Apothecary::Apothecary(int order, int shelf)
{
	potionShelf = new PotionShelf(shelf);
	orderList = new OrderQueue(order);
}


// Purchases the available Potion from the Apothecary (if possible)
// Otherise, slogs off in shame, probably to get eaten by a dragon
// Pre-condition: None
// Post-condition: Potion stack no longer has front potion
// Returns: Success/failure
bool Apothecary::BuyPotion(Potion& potion)
{
	if ( !potionShelf->isEmpty() )
		potion = potionShelf->peek();
	return ( potionShelf->pop() );
}

// Takes orders for Potions, up to size of orderLimit
// Pre-condition: A potion
// Post-codition: Potion is the last potion in queue
// Returns: Success/failure to add
bool Apothecary::OrderPotion(PotionType potion)
{
	bool orderAccepted = false;
	if ( orderList->enqueue(potion) )
		orderAccepted = true;	
	return orderAccepted;
}

// Manufactures potions from the orderQueue; 
// no unicorns were harmed in the making of these potions
// Pre-condition: None
// Post-condition: stackPtr points to front potion on shelf
// Returns: Number of potions made
int Apothecary::MakePotions()
{
	int potionsMade = 0;
	Potion *madePotion;
	
	while ( !orderList->isEmpty() ) {
		madePotion = new Potion(orderList->peekFront());
		if ( static_cast<PotionShelf*>(potionShelf)->isFull() ) {
			std::cout << "The shelf of potions is full.  You can't make any more until somebody buys some." << std::endl;
            delete madePotion;
			break;
		} else if ( potionShelf->push(*madePotion) ) {
			std::cout << "Made a " << PotionTypeString( orderList->peekFront() ) << " potion." << std::endl;
			orderList->dequeue();
			potionsMade++;
            delete madePotion;
		}
        
	}
    madePotion = nullptr;
	return potionsMade;
}

// Destructor
Apothecary::~Apothecary()
{
	while ( !(potionShelf->isEmpty() ) )
		potionShelf->pop();
	delete potionShelf;
	potionShelf = nullptr;
	
	while ( !(orderList->isEmpty() ) )
		orderList->dequeue();
	delete orderList;
	orderList = nullptr;
}
