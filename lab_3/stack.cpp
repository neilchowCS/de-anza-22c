#ifndef STACK_H
#define STACK_H
#include "singlyLinkedList.cpp"
#include <string>

class Stack:private SinglyLinkedList {
	public:
		Stack();
		~Stack();

		void push(Currency*);
		Currency* pop();
		Currency* peek();
		std::string printStack();
};

Stack::Stack() {};

Stack::~Stack() {};

// Adds the given currency to the top of the stack
// Pre:
//	x - Currency to add
// Post:
//	a LinkNode is added to the top of the stack
// Return:
void Stack::push(Currency* x) {
	this->addCurrency(x, 0);
	// if (this->isEmpty()){
	// 	this->setStart(new LinkNode(x));
	// 	this->setEnd(this->getStart());
	// }else{
	// 	LinkNode* temp = this->getStart();
	// 	this->setStart(new LinkNode(x));
	// 	this->getStart()->next = temp;
	// }
	// this->setCount(this->countCurrency() + 1);
}

// Removes and returns the first value on the stack
// Pre:
// Post:
//	removes the first value on the stack
// Return:
//	the first value on the stack
Currency* Stack::pop() {
	// if (this->isEmpty()){
	// 	return nullptr;
	// }
	// LinkNode* temp = this->getStart();
	// this->setStart(this->getStart()->next);
	// this->setCount(this->countCurrency() - 1);
	// if (countCurrency() == 0){
	// 	this->setEnd(nullptr);
	// }
	// return temp->data->getCopy();
	return this->removeCurrency(0);
}

// Returns the first value on the stack
// Pre:
// Post:
// Return:
//	the first value on the stack
Currency* Stack::peek() {
	// if (this->isEmpty()){
	// 	return nullptr;
	// }
	return this->getStart()->data->getCopy();
}

// Returns a tab spaced string representing the stack
// Pre:
// Post:
// Return:
//	a string representation of the stack
std::string Stack::printStack() {
	return this->printList();
}

#endif