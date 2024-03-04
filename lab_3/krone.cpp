// Changes from lab 2
// Removed many functions because we figured out how to
// inherit functions properly from Currency.
// Removed functions included:
//    print();
//    add(Currency &x);
//    subtract(Currency &x);
//    isEqual(Currency &x);
//    isGreater(Currency &x);
// We added getName(), which is used to return the name of the object
// And we added getCopy() to return a copy of the object
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

        std::string getName();
        Currency* getCopy();
};

Krone::Krone() {
}

Krone::Krone(double x) 
    : Currency(x) {
}

// Returns the name of the currency
// Pre:
// Post:
// Returns:
//    string - name of the current object
std::string Krone::getName() {
    return name;
}

// Returns a pointer to a currency object with the same values
// Pre:
// Post:
// Returns:
//    a pointer to a currency object with the same values
Currency* Krone::getCopy(){
    return new Krone((getWhole()) + ((double)getFraction())/100);
}

#endif