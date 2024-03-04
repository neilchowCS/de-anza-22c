#ifndef BST_H
#define BST_H
#include "bstNode.cpp"
#include "currency.cpp"
#include "krone.cpp"
#include "queue.cpp"

class BinarySearchTree {
private:
  int count;
  BstNode *root;

  void preOrderTraversalHelper(Queue *, BstNode *);
  void postOrderTraversalHelper(Queue *, BstNode *);
  BstNode *searchHelper(BstNode *, Currency *);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  BstNode *getRoot();
  int getCount();

  bool isEmpty();

  void insert(Currency *);
  void deleteNode(Currency *);
  BstNode *search(Currency *);
  std::string print();
  void empty();

  std::string breadthFirstTraversal();
  std::string inOrderTraversal();
  std::string preOrderTraversal();
  std::string postOrderTraversal();

  void queuePush(Queue &queue1, Queue &queue2, Currency *x);
};

BinarySearchTree::BinarySearchTree() {
  count = 0;
  root = NULL;
}

BinarySearchTree::~BinarySearchTree() {}

// Getters for the BST
BstNode *BinarySearchTree::getRoot() { return root; }

int BinarySearchTree::getCount() { return count; }

bool BinarySearchTree::isEmpty() { return (count == 0); }

// Inserts the given value into the BST
// Pre:
//	x - the data to insert
// Post:
//	a bstNode is inserted into the BST
// Return:
void BinarySearchTree::insert(Currency *x) {
  count += 1;
  if (root == NULL) {
    root = new BstNode(x);
  } else {

    if (search(x)) {
      std::cout << x->print() << " Duplicate entry" << std::endl;
      count--;
      return;
    }

    BstNode *newNode = new BstNode(x);
    BstNode *currentNode = root;
    while (currentNode != NULL) {
      if (currentNode->data->isGreater(*newNode->data)) {
        if (currentNode->left == NULL) {
          currentNode->left = newNode;
          currentNode = NULL;
        } else {
          currentNode = currentNode->left;
        }
      } else {
        if (currentNode->right == NULL) {
          currentNode->right = newNode;
          currentNode = NULL;
        } else {
          currentNode = currentNode->right;
        }
      }
    }
  }
}

// Removes the node with the specified data from the BST
// Pre:
//  Currency - the data of the node to be removed
// Post:
//  a node is removed from the BST
// Return:
void BinarySearchTree::deleteNode(Currency *x) {
  BstNode *parNode = NULL;
  BstNode *curNode = root;
  while (curNode != NULL) {
    if (curNode->data->isEqual(*x)) {
      if (curNode->left == NULL && curNode->right == NULL) {
        if (parNode == NULL) {
          root = NULL;
        } else if (parNode->left == curNode) {
          parNode->left = NULL;
        } else {
          parNode->right = NULL;
        }
      } else if (curNode->right == NULL) {
        if (parNode == NULL) {
          root = curNode->left;
        } else if (parNode->left == curNode) {
          parNode->left = curNode->left;
        } else {
          parNode->right = curNode->left;
        }
      } else if (curNode->left == NULL) {
        if (parNode == NULL) {
          root = curNode->right;
        } else if (parNode->left == curNode) {
          parNode->left = curNode->right;
        } else {
          parNode->right = curNode->right;
        }
      } else {
        BstNode *sucNode = curNode->right;
        while (sucNode->left != NULL) {
          sucNode = sucNode->left;
        }
        Currency *copy = sucNode->data->getCopy();
        deleteNode(copy);
        curNode->data = copy;
      }
      return;
    } else if (x->isGreater(*curNode->data)) {
      parNode = curNode;
      curNode = curNode->right;
    } else {
      parNode = curNode;
      curNode = curNode->left;
    }
  }
  return;
}

// Returns the node with the specified value
// Pre:
//  x - the data of the node to find
// Post:
// Return:
//  the node with the specified value
BstNode *BinarySearchTree::search(Currency *x) { return searchHelper(root, x); }

// Recursively looks through the BST to find the node with the specified value
// Pre:
//  node - the BstNode to check for equivilancy
//  x - the data of the node to find
// Post:
// Return:
//  the node with the specified value
BstNode *BinarySearchTree::searchHelper(BstNode *node, Currency *x) {
  if (node == nullptr || node->data->isEqual(*x)) {
    return node;
  }
  if (x->isGreater(*(node->data))) {
    return searchHelper(node->right, x);
  }
  return searchHelper(node->left, x);
}

// Returns a string of the Bst with breadthFirstTraversal.
// Pre:
// Post:
// Return:
//	a string representation of the BST in preOrderTraversal
std::string BinarySearchTree::breadthFirstTraversal() {
  if (root == NULL) {
    return "";
  }

  Queue queue;
  Queue output;

  queue.enqueue(root->data);
  while (queue.peekFront() != nullptr) {
    BstNode *node = search(queue.peekFront());
    output.enqueue(node->data);
    queue.dequeue();
    if (node->left != NULL) {
      queue.enqueue(node->left->data);
    }
    if (node->right != NULL) {
      queue.enqueue(node->right->data);
    }
  }

  return output.printQueue();
}

// Adds element to front of queue1, emulating stack behavior. Dequeue and peek
// work as
// normal on queue1
//
// Pre: two existing queues, one main queue1 and one accessory queue2
// Post: currency x pushed to front of queue1
// Return:
void BinarySearchTree::queuePush(Queue &queue1, Queue &queue2, Currency *x) {
  queue2.enqueue(x);

  while (!(queue1.peekFront() == nullptr)) {
    queue2.enqueue(queue1.peekFront());
    queue1.dequeue();
  }

  Queue q = queue1;
  queue1 = queue2;
  queue2 = q;
}

// Retruns a string representation of the BST of the nodes from least to
// greatest Pre: Post: Return:
//  a string of the BST nodes from least to greatest
std::string BinarySearchTree::inOrderTraversal() {
  Queue output;
  Queue q1;
  Queue q2;
  BstNode *currentNode = root;

  while (currentNode != nullptr || q1.peekFront() != nullptr) {
    while (currentNode != nullptr) {
      queuePush(q1, q2, currentNode->data);
      currentNode = currentNode->left;
    }

    currentNode = search(q1.peekFront());
    q1.dequeue();

    output.enqueue(currentNode->data);

    currentNode = currentNode->right;
  }
  return output.printQueue();
}

// Returns a string of the BST with preOrderTraversal. Visit the node first,
// then it's left children, then it's right
// Pre:
// Post:
// Return:
//	a string representation of the BST in preOrderTraversal
std::string BinarySearchTree::preOrderTraversal() {
  if (root == NULL) {
    return "Empty Tree";
  }
  Queue *queue = new Queue;
  preOrderTraversalHelper(queue, root);
  return queue->printQueue();
}

// Recursively adds the nodes of the BST to the given queue for
// preOrderTraversal Pre:
//	queue - the queue to add nodes to
//	x - the node to add to the queue and call the function again on its left
// and right
// Post:
//	add another node to the queue
// Return:
void BinarySearchTree::preOrderTraversalHelper(Queue *queue, BstNode *x) {
  if (x == NULL) {
    return;
  }
  queue->enqueue(x->data);
  preOrderTraversalHelper(queue, x->left);
  preOrderTraversalHelper(queue, x->right);
}

// Returns a string of the BST with postOrderTraversal. Visit the lowest level
// left child, then the right, then the parent. Pre: Post: Return:
//  a string representing the data of the BST in postOrderTraversal
std::string BinarySearchTree::postOrderTraversal() {
  if (root == NULL) {
    return "Empty Tree";
  }
  Queue *queue = new Queue;
  postOrderTraversalHelper(queue, root);
  return queue->printQueue();
}

// Recursively adds the nodes of the BST to the given queue for
// postOrderTraversal Pre:
//	queue - the queue to add nodes to
//	x - the node to add to the queue and call the function again on its left
// and right
// Post:
//	add another node to the queue
// Return:
void BinarySearchTree::postOrderTraversalHelper(Queue *queue, BstNode *x) {
  if (x == NULL) {
    return;
  }
  postOrderTraversalHelper(queue, x->left);
  postOrderTraversalHelper(queue, x->right);
  queue->enqueue(x->data);
}

// Deletes the BST
// Pre:
// Post:
//  the BST is gone
// Return:
void BinarySearchTree::empty() { this->root = nullptr; }

#endif
