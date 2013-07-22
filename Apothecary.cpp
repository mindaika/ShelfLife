#include "Apothecary.h"

// Default Constuctor
Apothecary::Apothecary()
{
	orderLimit = 20;
	shelfLimit = 5;
	potionsOnShelf = 0;
	orderQueue = nullptr;
	orderHead = nullptr;
	orderCount = 0;
	stackPtr = nullptr;
	PotionShelf* potionShelf = new PotionShelf();
	OrderQueue* orderList = new OrderQueue();
}


// Constructor
Apothecary::Apothecary(int order, int shelf)
{
	orderLimit = order;
	shelfLimit = shelf;
	potionsOnShelf = 0;
	orderQueue = nullptr;
	orderHead = nullptr;
	orderCount = 0;
	stackPtr = nullptr;
	PotionShelf* potionShelf = new PotionShelf(shelf);
	OrderQueue* orderList = new OrderQueue(order);
}


// Purchases the available Potion from the Apothecary (if possible)
// Otherise, slogs off in shame, probably to get eaten by a dragon
// Pre-condition: None
// Post-condition: Potion stack no longer has front potion
// Returns: Success/failure
bool Apothecary::BuyPotion(Potion& potion)
{
	bool successFlag = false;
	//Potion *popper;
	//if ( !(stackPtr == nullptr) ) {
	//	potion = *stackPtr;
	//	popper = stackPtr;
	//	stackPtr = stackPtr->getNextPotion();
	//	delete popper;
	//	successFlag = true;
	//	potionsOnShelf--;
	//}
	return successFlag;
}

// Takes orders for Potions, up to size of orderLimit
// Pre-condition: A potion
// Post-codition: Potion is the last potion in queue
// Returns: Success/failure to add
bool Apothecary::OrderPotion(PotionType potion)
{
	bool orderAccepted = false;
	
	/*Potion *nextOrder;

	if ( orderCount < orderLimit ) {
		nextOrder = new Potion(potion);
		if ( orderHead == nullptr ) {
			orderHead = nextOrder;
			orderQueue = nextOrder;
		} else {
			orderQueue->setNextPotion(nextOrder);
			orderQueue = nextOrder;
		}
		orderCount++;
		orderAccepted = true;
	} else {
		orderAccepted = false;
	}
	*/
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
	
	/*
	Potion *order = nullptr;
	order = orderHead;
	orderHead = orderHead->getNextPotion();
	*/
	/*
	Potion *order = nullptr;
	while ( (potionsOnShelf < shelfLimit) && !(orderHead == nullptr) ) {
		Potion *nextPotion = new Potion(orderHead->GetType());
		nextPotion->setNextPotion(stackPtr);
		order = orderHead;
		orderHead = orderHead->getNextPotion();
		delete order;
		stackPtr = nextPotion;
		std::cout << "Made a " << PotionTypeString(nextPotion->GetType()) << " potion." << std::endl;
		potionsOnShelf++;
		potionsMade++;
	}
	if ( (potionsOnShelf == shelfLimit) && !(orderHead == nullptr) ) {
		cout << "The shelf of potions is full.  You can't make any more until somebody buys some." << endl;
	}
	orderCount = 0;*/
	return potionsMade;
}

// Destructor
Apothecary::~Apothecary()
{
	/*Potion* killJoy = nullptr;
	
	while ( !(stackPtr == nullptr) ) {
		killJoy = stackPtr->getNextPotion();
		delete stackPtr;
		stackPtr = killJoy;
	}

	while ( !(orderHead == nullptr) ) {
		killJoy = orderHead->getNextPotion();
		delete orderHead;
		orderHead = killJoy;
	}

	orderQueue = nullptr;*/
}