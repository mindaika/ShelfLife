#include "OrderQueue.h"

OrderQueue::OrderQueue(void)
{
	orderLimit = 10;
	currentOrders = 0;
}

OrderQueue::OrderQueue(int limit)
{
	orderLimit = limit;
	currentOrders = 0;
}

bool OrderQueue::enqueue(const Potion& potion)
{
	bool successful = false;
	if ( currentOrders < orderLimit ) {
		ListQueue::enqueue(potion);
		currentOrders++;
		successful = true;
	}
	return successful;
}

OrderQueue::~OrderQueue(void)
{
}
