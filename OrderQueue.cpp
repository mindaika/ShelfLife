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

bool OrderQueue::enqueue(const PotionType& potion)
{
	bool successful = false;
	if ( currentOrders < orderLimit ) {
		ListQueue::enqueue(potion);
		currentOrders++;
		successful = true;
	}
	return successful;
}

bool OrderQueue::dequeue() 
{
	currentOrders--;
	return( ListQueue::dequeue() );
}

OrderQueue::~OrderQueue(void)
{
	while ( !this->isEmpty() )
		this->dequeue();
	std::cout << "OrderQueue Death" << std::endl;
}
