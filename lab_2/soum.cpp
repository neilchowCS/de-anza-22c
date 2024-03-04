#ifndef SOUM_H
#define SOUM_H
#include "currency.cpp"
#include <string>

class Soum:public Currency{
    private:
        std::string name = "Soum";

    public:
        Soum();
        Soum(double x);

        void print();
        std::string getName();
};

Soum::Soum() {
}

Soum::Soum(double x) 
    : Currency(x) {
}

// Prints the whole, fraction, and name values of the object
// Pre:
// Post:
// Returns:
void Soum::print() {
        std::cout << whole << "." << fraction << " " << name;
}

// Returns the name of the currency
// Pre:
// Post:
// Returns:
//    string - name of the current object
std::string Soum::getName() {
    return name;
}

#endif