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
	int orderLimit; // Size of order queue
	int shelfLimit; // Size of shelf stack
	int orderCount; // Current number of orders
	int potionsOnShelf; // Number of potions currently on shelf
	Potion *orderQueue; // Pointer to the current order on the queue
	Potion *orderHead; // Pointer to the start of the order queue
	Potion *stackPtr; // Pointer to the top of the shelf stack
	StackInterface<Potion> *potionShelf; // The damn potion shelf
	ListInterface<Potion> *orderList; // The order list
public:
	Apothecary();
	Apothecary(int, int);
	~Apothecary();
	bool BuyPotion(Potion&);
	bool OrderPotion(PotionType);
	int MakePotions();
};
#endif