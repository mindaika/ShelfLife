#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE

template<class ItemType>
class QueueInterface
{
public:
	// Test whether queue is empty
	// Returns: True if empty; false otherwise
	virtual bool isEmpty() const = 0;

	// Adds new entry at end of Queue
	// Precondition: None
	// Postcondition: newEntry is at end of Queue
	// Returns: True is successful; false otherwise
	virtual bool enqueue(const ItemType& newEntry) = 0;

	// Removes front item from Queue
	// Precondition: Queue contains items
	// Postcondition: Front of Queue has been removed
	virtual bool dequeue() = 0;

	// Determines front item in queue
	// Precondition: Queue contains items
	// Postcondition: Queue is unchanged
	// Returns: Front of Queue
	virtual ItemType peekFront() const = 0;
    
    virtual ~QueueInterface() = 0;
};

// Requires virtual destructor definition
template<class ItemType>
QueueInterface<ItemType>::~QueueInterface() { }
#endif

