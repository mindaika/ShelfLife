#ifndef _ORDER_QUEUE
#define _ORDER_QUEUE

#include "ListQueue.h"
#include "Potion.h"

// OrderQueue managaes a list of orders of PotionType
class OrderQueue : public ListQueue<PotionType>
{
private:
	int orderLimit; // Maximum number of orders to allow
	int currentOrders; // Current number of orders taken
public:
	// Constructors & desctructors
    OrderQueue(void);
	OrderQueue(int);
	~OrderQueue(void);

    // Override of base class to allow for shelf operations
	bool enqueue(const PotionType&);
	bool dequeue();
};
#endif

