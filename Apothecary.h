#ifndef _APO
#define _APO
#include "main.h"
#include "Potion.h"

// Apothecary Class
// Creates an Apothecary Shop with an Order Limit and Shelf Limit
class Apothecary
{
private:
	int orderLimit; // Size of order queue
	int shelfLimit; // Size of shelf stack
	int orderCount; // Current number of orders
	int potionsOnShelf; // Number of potions currently on shelf
	Potion *orderQueue;
	Potion *orderHead;
	Potion *headPtr;
public:
	Apothecary();
	Apothecary(int, int);
	~Apothecary();
	bool BuyPotion(Potion&);
	bool OrderPotion(PotionType);
	int MakePotions();
};
#endif