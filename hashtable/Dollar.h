/*============
Lab 5 - Hash Tables
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a hash table with quadratic probing and apply multiple operations to practice with hash tables.
============*/
#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"

class Dollar : public Currency {

private:
    std::string* type;

public:

    // Constructors and Destructor
    Dollar();
    Dollar(double money);
    ~Dollar();

    // Getter function
    std::string getType();

    //HIGHLIGHT: Change
    Currency* copyCurrency();
};

Dollar::Dollar() : Currency(0) {
    type = new std::string("Dollar");
}

Dollar::Dollar(double money) : Currency(money) {
    if (money < 0)
        throw "Invalid negative value";
    type = new std::string("Dollar");
}

Dollar::~Dollar() {
    delete type;
    type = nullptr;
}

/*
This function returns the currency type "Dollar" as a string.
Pre:
Post:
Return: "Dollar" (Currency type as a string)
*/
std::string Dollar::getType() {
    return *type;
}

/*
This function copies this currency object to another one and returns it.
Pre:
Post:
Return: Currency* object copy of this object
*/
Currency* Dollar::copyCurrency() {

    Currency* copy = new Dollar();
    copy->setWhole(this->getWhole());
    copy->setFraction(this->getFraction());
    return copy;

}

#endif