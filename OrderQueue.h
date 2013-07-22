#ifndef _ORDER_QUEUE
#define _ORDER_QUEUE

#include "ListQueue.h"
#include "Potion.h"

class OrderQueue : public ListQueue<Potion>
{
private:
	int orderLimit;
	int currentOrders;
public:
	OrderQueue(void);
	OrderQueue(int);
	~OrderQueue(void);

	bool enqueue(const Potion&); 
};
#endif

