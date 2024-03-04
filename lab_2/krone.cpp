#ifndef KRONE_H
#define KRONE_H
#include "currency.cpp"
#include <string>

class Krone:public Currency{
    private:
        std::string name = "Krone";

    public:
        Krone();
        Krone(double x);

        void print();
        std::string getName();
};

Krone::Krone() {
}

Krone::Krone(double x) 
    : Currency(x) {
}

// Prints the whole, fraction, and name values of the object
// Pre:
// Post:
// Returns:
void Krone::print() {
        std::cout << whole << "." << fraction << " " << name;
}

// Returns the name of the currency
// Pre:
// Post:
// Returns:
//    string - name of the current object
std::string Krone::getName() {
    return name;
}

#endif