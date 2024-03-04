#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "typeinfo"

class Currency {
protected:
    int whole;
    int fraction;

public:
    Currency();
    Currency(double x);
    Currency(const Currency& x);
    virtual ~Currency();

    int getWhole();
    int getFraction();
    void setWhole(int x);
    void setFraction(int x);

    virtual void add(Currency& x);
    virtual void subtract(Currency& x);
    virtual bool isEqual(Currency& x);
    virtual bool isGreater(Currency& x);
    virtual void print();
    virtual std::string getName() = 0;
};

Currency::Currency() {
    whole = 0;
    fraction = 0;
}

Currency::Currency(double x) {
    try {
        if (x < 0) {
            throw x;
        }
    } catch (double) {
        whole = 0;
        fraction = 0;
        std::cerr << "Invalid input, must be non-negative" << '\n';
        return;
    }

    double intpart;
    double fractpart;
    fractpart = modf(x, &intpart);

    whole = intpart;
    fraction = std::round(fractpart * 100);
}

Currency::Currency(const Currency& x) {
    whole = x.whole;
    fraction = x.fraction;
}

Currency::~Currency() {
}

// The following two methods are getters for the whole and fraction values
// of the object
// Pre:
// Post:
// Returns:
//    int - the whole or fractional value of the object
int Currency::getWhole() {
    return whole;
}

int Currency::getFraction() {
    return fraction;
}

// The following two methods are setters for the whole and fractional values
// Pre:
//    x - the new value for the whole or fractional value of the object
// Post:
// Returns:
void Currency::setWhole(int x) {
    try {
        if (x < 0) {
            throw x;
        }
    } catch (int) {
        std::cerr << "Invalid input, must be non-negative" << '\n';
        return;
    }

    whole = x;
}

void Currency::setFraction(int x) {
    while (x > 100) {
        x = x / 10;
    }

    try {
        if (x < 0) {
            throw x;
        }
    } catch (int) {
        std::cerr << "Invalid input, must be non-negative" << '\n';
        return;
    }
    fraction = x;
}

// Adds the value of the given currency object to the one being called
// Pre:
//    x - a reference to another currency object
// Post:
//    whole - value of the current object
//    fraction - value of the current object
// Returns:
void Currency::add(Currency& x) {
    try {
        if (x.getName() != this->getName()) {
            throw std::invalid_argument("Invalid addition, must be the same currency");
        }
    } catch (const std::exception) {
        std::cerr << "Invalid addition" << '\n';
        return;
    }
    fraction = fraction + x.getFraction();

    if (fraction > 100) {
        fraction = fraction - 100;
        whole += 1;
    }

    whole = whole + x.getWhole();
}

// Subtracts the value of the given currency object from the one being called
// Pre:
//    x - a reference to another currency object
// Post:
//    whole - value of the current object
//    fraction - value of the current object
// Returns:
void Currency::subtract(Currency& x) {
    int otherWhole = x.getWhole();
    int otherFraction = x.getFraction();

    try {
        if (x.getName() != this->getName()) {
            throw std::invalid_argument("Invalid subtraction, must be the same currency");
        }
    } catch (const std::exception) {
        std::cerr << "Invalid subtraction" << '\n';
        return;
    }

    try {
          if (otherWhole > whole || (otherWhole == whole && otherFraction > fraction)) {
            throw std::invalid_argument("Invalid subtraction");
        }
    } catch (const std::exception) {
        std::cerr << "Invalid subtraction" << '\n';
        return;
    }

    if ((fraction - otherFraction) < 0) {
        fraction = fraction - otherFraction + 100;
        whole -= 1;
    } else {
        fraction -= otherFraction;
    }

    whole -= otherWhole;
}

// Compares the whole and fraction values for equality
// Pre:
//    x - A reference to another currency object
// Post:
// Returns:
//    bool - true if the two objects are equal, false otherwise
bool Currency::isEqual(Currency& x) {
    try {
        if (x.getName() != this->getName()) {
            throw std::invalid_argument("Invalid comparison, must be the same currency");
        }
    } catch (const std::exception) {
        std::cerr << "Invald comparison" << '\n';
        return false;
    }

    if (x.getWhole() == whole && x.getFraction() == fraction) {
        return true;
    } else {
        return false;
    }
}

// Compares the values of the given currency object
// Pre:
//    x - A reference to another currency object
// Post:
// Returns:
//    bool - true if the current object is greater than the given object, false otherwise
bool Currency::isGreater(Currency& x) {
    int otherWhole = x.getWhole();
    int otherFraction = x.getFraction();

    try {
        if (x.getName() != this->getName()) {
            throw std::invalid_argument("Invalid comparison, must be the same currency");
        }
    } catch (const std::exception) {
        std::cerr << "Invald comparison" << '\n';
        return false;
    }

    if (otherWhole < whole || (otherWhole == whole && otherFraction < fraction)) {
        return true;
    } else {
        return false;
    }
}

#endif
