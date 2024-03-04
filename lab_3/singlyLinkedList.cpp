#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <string>
#include "currency.cpp"
#include "linkNode.cpp"

class SinglyLinkedList {
  private:
    int count;
    LinkNode* start;
    LinkNode* end;

  public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    LinkNode* getStart();
    LinkNode* getEnd();

    void addCurrency(Currency*, int);
    Currency* removeCurrency(int);
    Currency* removeCurrency(Currency*);
    int findCurrency(Currency*);
    Currency* getCurrency(int);
    virtual std::string printList();
    bool isEmpty();
    int countCurrency();
};

SinglyLinkedList::SinglyLinkedList() {
  count = 0;
  start = NULL;
  end = NULL;
}

SinglyLinkedList::~SinglyLinkedList() {}

LinkNode* SinglyLinkedList::getStart(){
  return start;
}

LinkNode* SinglyLinkedList::getEnd(){
  return end;
}

// Adds a LinkNode to the list at the specified index, or to the end if unspecified
// Pre:
//  x - a pointer to a Currency object
//  index - desired index of the new node
// Post:
//  adds a LinkNode to the current SinglyLinkedList at the specified index
// Return:
void SinglyLinkedList::addCurrency(Currency* x, int index = -1) {
  if (start == NULL) {
    start = new LinkNode(x);
    end = start;
    count += 1;
    return;
  }

  LinkNode* newNode = new LinkNode(x);
  if (index >= count || index == -1) {
    end->next = newNode;
    end = newNode;
  } else if (index == 0) {
    newNode->next = start;
    start = newNode;
  } else {
    LinkNode* prevNode = start;
    int i = 0;
    while (i < index - 1) {
      prevNode = prevNode->next;
      i++;
    }
    LinkNode* nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->next = nextNode;
  }
  count += 1;
}

// Returns a string of the list
// Pre:
// Post:
// Return:
//   a tab spaced string of the currency objects in each node of the list
std::string SinglyLinkedList::printList() {
  std::string stringList = "";
  LinkNode* currentNode = start;

  if (this->isEmpty()) {
    return "Empty list";
  }

  while (currentNode->next != NULL) {
    stringList += currentNode->data->print() + '\t';
    currentNode = currentNode->next;
  }
  stringList += currentNode->data->print() + '\t';

  return stringList;
}

// Checks if the list is empty or not
// Pre:
// Post:
// Return:
//  true if the list is empty, false if not
bool SinglyLinkedList::isEmpty() {
  if (count == 0) {
    return true;
  } else {
    return false;
  }
}


// Finds the index of the given currency in the list
// Pre:
//  x - Currency value to find
// Post:
// Return:
//  the index of the Currency in the list, otherwise -1
int SinglyLinkedList::findCurrency(Currency* x){
  LinkNode *currentNode = start;
  if (this->isEmpty()) {
    return -1;
  }

  // do{
  //   if (currentNode->data->isEqual(*x)){
  //     return count;
  //   }
  //   currentNode = currentNode->next;
  //   count ++;
  //   }
  // while (currentNode != end);
  int index = 0;
  while (currentNode->next != NULL) {
    if (currentNode->data->isEqual(*x)) {
      return index;
    }
    currentNode = currentNode->next;
    index++;
  }
  if (currentNode->data->isEqual(*x)) {
    return index;
  }

  return -1;
}

// Removes the node at the specified index
// Pre:
//  index - the index of the node to remove
// Post:
//  removes the node from the list
// Return:
//  the data of the deleted node
Currency* SinglyLinkedList::removeCurrency(int index) {
  if (this->isEmpty()) {
    return nullptr;
  }

  if (index < 0 || index > count - 1) {
    return nullptr;
  }

  count -= 1;
  if (isEmpty()){
    end = nullptr;
  }

  if (index == 0){
    start = start->next;
    return start->data->getCopy();
  } else {
    LinkNode *currentNode = start;
    for (int i = 0; i < index - 1; i++) {
      currentNode = currentNode->next;
    }
    LinkNode *temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    return temp->data->getCopy();
  }
}

// Removes the first node with the specified currency
// Pre:
//  x - the data of the node to remove
// Post:
//  removes the node from the list if found
// Return:
//  the data of the deleted node if found
Currency* SinglyLinkedList::removeCurrency(Currency* x) {
  if (this->isEmpty()) {
    return nullptr;
  }
  
  int index = findCurrency(x);
  return SinglyLinkedList::removeCurrency(index);
}

// Returns the currency data at the specified index
// Pre:
//  index - index of the node to get
// Post:
// Return:
//  the currency data at the index
Currency* SinglyLinkedList::getCurrency(int index) {
  if (index > count - 1 || index < 0) {
    return nullptr;
  }

  LinkNode *currentNode = start;
  for (int i = 0; i < index; i++) {
    currentNode = currentNode->next;
  }
  return currentNode->data->getCopy();
}

// Returns the number of nodes in the list
// Pre:
// Post:
// Return:
//  the number of nodes in the list
int SinglyLinkedList::countCurrency() {
  return count;
}

#endif
