// Lab 2 - Classes, Inheritance, and Polymorphism
// Alan Tran-Kiem, Neil Chow
// This lab shows how related classes can share and change methods between them

#include <math.h>
#include "currency.cpp"
#include "krone.cpp"
#include "soum.cpp"
#include <typeinfo>
#include "string"

int main() {
  bool run = true;
  std::cout << std::endl;
  Currency *c[2];
  c[0] = new Soum();
  c[1] = new Krone();
  
  c[0] -> print();
  std::cout << " ";
  c[1] -> print();
  std::cout << '\n';
  std::cout << '\n';
  while (run){
    int index;
    std::string s1;
    std::string s2;
    double i1;
    std::string s3;
    std::cout<< "Enter Input" << std::endl;
    std::cin >> s1;
    if (s1 == "q"){
      return 0;
    }
    std::cin >> s2 >> i1 >> s3;
    if (s3 == "Soum"){
      Currency *s = new Soum(i1);
      if (s2 == "s"){
        index = 0;
      }else if (s2 == "k"){
        index = 1;
      }
      if (s1 == "a"){
        c[index] -> add(*s);
      }else if (s1 == "s"){
        c[index] -> subtract(*s);
      }
    }else if (s3 == "Krone"){
      Currency *k = new Krone(i1);
      if (s2 == "s"){
        index = 0;
      }else if (s2 == "k"){
        index = 1;
      }
      if (s1 == "a"){
        c[index] -> add(*k);
      }else if (s1 == "s"){
        c[index] -> subtract(*k);
      }
    }
    c[0] -> print();
    std::cout << " ";
    c[1] -> print();
    std::cout << '\n';
    std::cout << '\n';
    }


  return 0;
}
