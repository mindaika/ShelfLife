#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE
// Adapted from Carrano, 2013

template<class ItemType>
class StackInterface
{
public:
	// Test to see if stack is empty;
	// Returns: true if empty; false otherwise
	virtual bool isEmpty() const = 0;

	// Add new item to stack
	// Precondition: None
	// Postcondition: New object added to stack
	// Returns: True is successful, false otherwise
	virtual bool push(const ItemType& newEntry) = 0;

	// Removes item from stack
	// Precondition: Stack contains at least 1 item
	// Postcondition: Top of stack has been removed
	// Returns: True is successful, false otherwise
	virtual bool pop() = 0;

	// Returns top of the stack
	// Precondition: Stack contains at least 1 item
	// Postcondition: Top of stack has been returned, stack is unchanged
	// Returns: Top of the stack
	virtual ItemType peek() const  = 0;


};
#endif