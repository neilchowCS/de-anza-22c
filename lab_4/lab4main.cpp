// Lab 4 - BST ADT
// Alan Tran-Kiem, Niel Chow
// This lab implements a Binary Search Tree with Abstract Data Types as the data
// in the nodes

#include <fstream>
#include <iostream>

#include "binarySearchTree.cpp"
#include "krone.cpp"
#include <sstream>


std::string printTree(BinarySearchTree tree) {
  std::string allTraversals;
  allTraversals += "Printing with breadthFirstTraversal\n";
  allTraversals += tree.breadthFirstTraversal() + "\n";
  allTraversals += "Printing with inOrderTraversal\n";
  allTraversals += tree.inOrderTraversal() + "\n";
  allTraversals += "Printing with preOrderTraversal\n";
  allTraversals += tree.preOrderTraversal() + "\n";
  allTraversals += "Printing with postOrderTraversal\n";
  allTraversals += tree.postOrderTraversal() + "\n";
  return allTraversals;
}

int main() {
  std::cout << "Lab 4 - Binary Search Tree with Abstract Data Types" << '\n';

  Currency *curArray[21];

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
  // DUPLICATE CHECK
  curArray[20] = new Krone(151.00);

  BinarySearchTree bst;

  // Test with first ten elements
  for (int i = 0; i < 21; i++) {
    bst.insert(curArray[i]);
  }

  std::ofstream file;
  file.open("output.txt");

  std::cout << "Breadth First Traversal" << std::endl;
  std::cout << bst.breadthFirstTraversal() << std::endl;
  file << "Breadth First Traversal" << std::endl;
  file << bst.breadthFirstTraversal() << std::endl;

  std::cout << "Inorder Traversal" << std::endl;
  std::cout << bst.inOrderTraversal() << std::endl;
  file << "Inorder Traversal" << std::endl;
  file << bst.inOrderTraversal() << std::endl;

  std::cout << "Preorder Traversal" << std::endl;
  std::cout << bst.preOrderTraversal() << '\n';
  file << "Preorder Traversal" << std::endl;
  file << bst.preOrderTraversal() << '\n';

  std::cout << "Postorder Traversal" << '\n';
  std::cout << bst.postOrderTraversal() << std::endl;
  file << "Postorder Traversal" << '\n';
  file << bst.postOrderTraversal() << std::endl;

  std::cout << '\n';
  file << '\n';


  bool run = true;
  while (run) {
  std::string line;
  std::string input = "";
  double doubleInput = -1;
    std::cout << "Enter action (quit / print / add {x.x} / delete {x.x} / search "
                 "{x.x})"
              << std::endl;

    std::getline (std::cin,line);
    std::istringstream iss(line);
    iss >> input;
    iss >> doubleInput;

    if (input == "quit") {
      run = false;
      std::cout << printTree(bst) << '\n';
      file << "quit\n";
      file << printTree(bst) << '\n';
    } else if (input == "print") {
      std::cout << printTree(bst) << '\n';
      file << "print\n";
      file << printTree(bst) << '\n';
    } else if (input == "add" && doubleInput > 0) {
      bst.insert(new Krone(doubleInput));
      file << "add " << doubleInput << " Krone\n";
    } else if (input == "delete" && doubleInput > 0) {
      bst.deleteNode(new Krone(doubleInput));
      file << "delete " << doubleInput << " Krone\n";
    } else if (input == "search" && doubleInput > 0) {
      BstNode *node = bst.search(new Krone(doubleInput));

      if (node != nullptr) {
        std::cout << node->data->print() << std::endl;
        file << "search\n";
        file << node->data->print() << '\n';
      } else {
        std::cout << "Node not found" << std::endl;
        file << "Node not found" << '\n';
      }
    } else {
      std::cout << "invalid input: " << line << std::endl;
    }
  }

  file.close();
  return 0;
}
