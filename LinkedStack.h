#ifndef _LINKED_STACK
#define _LINKED_STACK
#pragma warning( disable : 4290 )

// Adapted from Carrano, 2013
// I can NOT, for the life of me, get VS12 to compile separate header/implementation templates

#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
	Node<ItemType>* topPtr;	// Points to first node in the stack
public:
	LinkedStack();	// Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack); // Copy constructor
	virtual ~LinkedStack(); // Destructor

	// Stack operations
	bool isEmpty() const;
	virtual bool push(const ItemType&);
	bool pop();
	ItemType peek() const throw(PrecondViolatedExcep);
};

// Default constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}

// Copy constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	// Point to nodes in original chain
	Node<ItemType>*origChainPtr = aStack->topPtr;

	if (origChainPtr == nullptr)
		topPtr = nullptr;
	else
	{
		// Copy first node
		topPtr = new Node<ItemType>();
		topPtr->setItem(origChainPtr->getItem());

		// Point to first node in new chain
		Node<ItemType>* newChainPtr = topPtr;

		// Copy remaining nodes
		while (origChainPtr != nullptr)
		{
			// Advance original chain pointer
			origChainPtr = origChainPtr->getNext();

			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create new Node with next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new Node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to last new Node
			newChainPtr = newChainPtr->getNext();
		}

		newChainPtr->setNext(nullptr); // End of chain
	}
}

// Tests for emptiness
// Ineffective on Rockbiters
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}

// Push
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
}

// Pop
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool successful = false;
	if (!isEmpty())
	{
		// Stack contains items; delete top item
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();

		// Destroy node
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		successful = true;
	}

	return successful;
}

// Peek
template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const throw(PrecondViolatedExcep)
{
	// Test for stack existence
	if (isEmpty())
		throw PrecondViolatedExcep("peek () called with an empty stack");

	// Return top item
	return topPtr->getItem();
}

// Destructor!
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop...
	// ALL THE THINGS!
	while (!isEmpty())
		pop();
}
#endif