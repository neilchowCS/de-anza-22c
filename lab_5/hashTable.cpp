#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "currency.cpp"
#include "krone.cpp"

class HashTable {
private:
  int count;
  int length;
  int collisions;
  Currency* curArray[29];
  int calcIndex(Currency*);

public:
  HashTable();
  ~HashTable();

  int getCollisions();
  double getLoadFactor();

  void insert(Currency *);
  std::string print();
  int search(Currency*);

  int getCount();
};

HashTable::HashTable() {
  count = 0;
  // curArray[size] = {};
  // length = size;
  length = 29;
  collisions = 0;
}

// Constructor and deconstructor
HashTable::~HashTable() {}

int HashTable::getCollisions() {
  return collisions;
}

// Getters
double HashTable::getLoadFactor() {
  return 1.0 * count / length;
} 

int HashTable::getCount(){
  return count;
} 

// Calculates the first index a value should have
// Pre:
//  x - the value to calculate the index of
// Post:
// Returns:
//  an integer that represents the index
int HashTable::calcIndex(Currency *x){
  int m = 2;
  int n = 3;
  int w = x->getWhole();
  int f = x->getFraction();
  
  return (m*w + n*f) % length;
}

// Inserts the given Currency into the HashTable.
// Uses a pseudorandom hash scheme of:
//  (m*w + n*f) % size
//  where size = 29, m = 2, n = 3, w = whole value, and f = fractional value
// Pre:
//  x - the value to insert
// Post:
//  a value is inserted into the HashTable
// Return:
void HashTable::insert(Currency *x) {
  int m = 2;
  int n = 3;
  int w = x->getWhole();
  int f = x->getFraction();
  int size = 29;

  int i = 0;
  int c1 = 2;
  int c2 = 3;
  
  int index = calcIndex(x);
  int originalIndex = calcIndex(x);
  while (true) {
    if (curArray[index] == nullptr) {
      curArray[index] = x;
      break;
    } else {
      i += 1;
      index = (originalIndex + c1 * i + c2 * i * i) % length;
      collisions += 1;
    }
  }
  curArray[index] = x;
  count++;
}

// Finds the index of the value in the HashTable
// Pre:
//  x - the value to find the index of
// Post:
// Returns:
//  an integer representing the index of the value, or -1 if not found
int HashTable::search(Currency* x){
  int visitedArray[29];
  for(int i = 0; i < 29; i++){
    visitedArray[i] = 0;
  }
  int visited = 0;
  int c1 = 2;
  int c2 = 3;
  int probeCount = 0;
  int original_index = calcIndex(x);

  while(visited < length){
    int index = (original_index + c1 * probeCount + c2 * probeCount * probeCount)%length;
    probeCount++;

    if (index >= 0 && curArray[index] != nullptr && curArray[index]->isEqual(*x)){
      return index;
    }else{
      if (visitedArray[index] == 0){
        // std::cout << index << std::endl;
        visitedArray[index] = 1;
        visited++;
      }
    }
  }
  return -1;
}

// Gives a string representation of the HashTable
// Pre:
// Post:
// Returns:
//  a string with the values of the HashTable in order, without the empty indexes
std::string HashTable::print() {
  std::string stringBuilder = "";
  for (int i = 0; i < length; i++) {
    if (curArray[i] == nullptr) {
      continue;
    }
    stringBuilder += curArray[i]->print();
    stringBuilder += + " ";
  }

  return stringBuilder;
}

#endif