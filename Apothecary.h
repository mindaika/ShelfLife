#ifndef _APO
#define _APO

#include "main.h"
#include "Potion.h"
#include "PotionShelf.h"
#include "OrderQueue.h"

// Apothecary Class
// Creates an Apothecary Shop with an Order Limit and Shelf Limit
// Manages the Stack implementation of the Shelf,
// and the Queue implementation of the Order queue
class Apothecary
{
private:
	StackInterface<Potion> *potionShelf; // The damn potion shelf
	QueueInterface<PotionType> *orderList; // The order list
public:
	Apothecary();
	Apothecary(int, int);
	~Apothecary();
	bool BuyPotion(Potion&);
	bool OrderPotion(PotionType);
	int MakePotions();
};
#endif