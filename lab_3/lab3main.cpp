// Lab 3 - Lists, Stacks, and Queues
// Alan Tran-Kiem, Niel Chow
// This lab implements link-based lists and derivative ADTs

#include "singlyLinkedList.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "currency.cpp"
#include "krone.cpp"

int main() {
  std::cout<< "Welcome to Neil and Alan's ADT demonstration" << std::endl;

  Currency *curArray[20];
  curArray[0] = new Krone(57.12);
  curArray[1] = new Krone(23.44);
  curArray[2] = new Krone(87.43);
  curArray[3] = new Krone(68.99);
  curArray[4] = new Krone(111.22);
  curArray[5] = new Krone(44.55);
  curArray[6] = new Krone(77.77);
  curArray[7] = new Krone(18.36);
  curArray[8] = new Krone(543.21);
  curArray[9] = new Krone(20.21);
  curArray[10] = new Krone(345.67);
  curArray[11] = new Krone(36.18);
  curArray[12] = new Krone(48.18);
  curArray[13] = new Krone(101.00);
  curArray[14] = new Krone(11.00);
  curArray[15] = new Krone(21.00);
  curArray[16] = new Krone(51.00);
  curArray[17] = new Krone(1.00);
  curArray[18] = new Krone(251.00);
  curArray[19] = new Krone(151.00);

  // Test list
  std::cout << "Testing list" << '\n';
  SinglyLinkedList list;

  for (int i = 0; i < 7; i++) {
    list.addCurrency(curArray[6 - i]);
  }
  std::cout << list.printList() << '\n';

  std::cout << list.findCurrency(new Krone(87.43)) << '\n';
  std::cout << list.findCurrency(new Krone(44.56)) << '\n';

  list.removeCurrency(new Krone(111.22));
  list.removeCurrency(2);
  std::cout << list.printList() << '\n';

  list.addCurrency(curArray[10], 0);
  list.addCurrency(curArray[11], 1);
  list.addCurrency(curArray[8], 3);
  list.addCurrency(curArray[9], 4);
  std::cout << list.printList() << '\n';

  list.removeCurrency(list.countCurrency() % 6);
  list.removeCurrency(list.countCurrency() / 7);
  std::cout << list.printList() << '\n';

  std::cout << '\n';

  // Test stack
  std::cout << "Testing stack" << '\n';
  Stack stack;
  for (int i = 13; i < 20; i++) {
    stack.push(curArray[i]);
  }

  std::cout << stack.peek()->print() << '\n';
  stack.pop();
  stack.pop();
  stack.pop();
  std::cout << stack.printStack() << '\n';

  for (int i = 0; i < 5; i++) {
    stack.push(curArray[i]);
  }
  stack.pop();
  stack.pop();
  std::cout << stack.printStack() << '\n';
  std::cout << '\n';

  // Test queue
  std::cout << "Testing queue" << '\n';
  Queue queue;

  for (int i = 0; i < 7; i++) {
    queue.enqueue(curArray[2 * i + 5]);
  }

  std::cout << queue.peekFront()->print() << '\n';

  queue.dequeue();
  queue.dequeue();

  std::cout << queue.printQueue() << '\n';

  for (int i = 10; i < 5; i++) {
    queue.enqueue(curArray[i]);
  }

  queue.dequeue();
  queue.dequeue();
  queue.dequeue();

  std::cout << queue.printQueue() << '\n';

  std::cout << "Program finished" << std::endl;

  return 0;
}
