#ifndef QUEUE_H
#define QUEUE_H
#include "singlyLinkedList.cpp"

class Queue:private SinglyLinkedList {
    public:
        Queue();
        ~Queue();

        void enqueue(Currency*);
        Currency* dequeue();
        Currency* peekFront();
        Currency* peekRear();
        std::string printQueue();

};

Queue::Queue() {};

Queue::~Queue() {};

// Adds a node to the back of the queue
// Pre:
//    x - The data the node will hold
// Post:
//    a node is added to the queue
// Returns:
void Queue::enqueue(Currency* x){
    this->addCurrency(x, -1);
}

// Removes and returns a node from the front of the queue
// Pre:
// Post:
//    a node is removed from the queue
// Returns:
//    the data of the removed node
Currency* Queue::dequeue(){
    return this->removeCurrency(0)->getCopy();
}

// Return the data from the first node in the queue
// Pre:
// Post:
// Returns:
//    the data of the first node
Currency* Queue::peekFront(){
    if (isEmpty()){
        return nullptr;
    }
    return this->getStart()->data->getCopy();
}

// Return the data from the last node in the queue
// Pre:
// Post:
// Returns:
//    the data from the last node
Currency* Queue::peekRear(){
    if (isEmpty()){
        return nullptr;
    }
    return this->getEnd()->data->getCopy();
}

// Prints the queue
// Pre:
// Post:
// Returns:
//    a string representing the data of the nodes in the queue
std::string Queue::printQueue() {
	return this->printList();
}

#endif