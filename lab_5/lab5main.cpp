#include "krone.cpp"
#include "hashTable.cpp"

int main() {
  std::cout << "Lab 5 - Hash Table with Abstract Data Types" << '\n';


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

  HashTable* curTable = new HashTable();
  
  //SEEDING DATA
  for (int i = 0; i < 20; i++){
    curTable->insert(curArray[i]);
  }
  std::cout << "Printing HashTable" << std::endl;
  std::cout << curTable->print() << '\n';
  std::cout << "Number of Data Items: " << curTable->getCount() << std::endl;
  std::cout << "Load Factor: " << curTable->getLoadFactor() << std::endl;
  std::cout << "Total Collisions: " << curTable->getCollisions() << std::endl;
  std::cout << "c1: 2, c2: 3" << '\n';
  
  bool run = true;
  while (run){
    std::cout << "To search for a Krone, enter: " << '\n';
    std::cout << "s {whole}.{fraction}" << '\n';
    std::string input;
    double numInput;
    std::cin >> input;
    if (input == "s"){
      std::cin >> numInput;
      std::cout << "Searching for " << numInput << std::endl;
      int search = curTable->search(new Krone(numInput));
      if (search == -1){
        std::cout << "Invalid Data" << std::endl;
      }else{
        std::cout << "Found at index " << search << std::endl;
      }
    }else{
      run = false;
      std::cout << "Quit Program" << std::endl;
    }
  }

  return 0;
}
