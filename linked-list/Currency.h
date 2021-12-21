/*============
Lab 3 - Lists, Stacks and Queues
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a singly-linked list and derivative ADTs (that use FIFO and LIFO) to practice with linear lists.
============*/
/* HIGHLIGHT: CHANGE ====================
    The print() function was changed to print directly to the console instead of returning
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
    The pure virtual function copyCurrency() was introduced to make a copy of the currency objects so as to not accidentally alter it later on
==================== HIGHLIGHT: CHANGE */
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <iomanip>

class Currency {
  
  private:
    int *whole;
    int *fraction;
    void normalize();

  public:

    // Constructors and Destructor
    Currency();
    Currency(double money);
    virtual ~Currency();

    // Required functions 
    void add(Currency* otherObject);
    void subtract(Currency* otherObject);
    bool isEqual(Currency* otherObject) const;
    bool isGreater(Currency* otherObject) const;

    /* HIGHLIGHT: CHANGE ====================
        Instead of returning from this function, this function is changed to print directly to the console
    ==================== HIGHLIGHT: CHANGE */
    void print();

    // Get currency type from child classes
    virtual std::string getType() = 0;

    // Setters and Getters
    void setWhole(int value);
    void setFraction(int value);
    int getWhole() const;
    int getFraction() const;

    virtual Currency* copyCurrency() = 0;

};

Currency::Currency() {

  std::cout << "Constructor\n";
  whole = new int(0);
  fraction = new int(0);

}

Currency::Currency(double money) {

  if (money < 0) {
    throw "Invalid negative value";
  } else {
    whole = new int (static_cast<int>(money));
    fraction = new int (static_cast<int>(((money - *whole * 1.0) * 100) + 0.5));
  }

}

Currency::~Currency() {
  delete whole;
  whole = nullptr;
  delete fraction;
  fraction = nullptr;
}

/*
This function adds the value of a currency of the same object to the value of a calling object.
Pre: otherObject - Pointer to an object of the same Currency type
Post: If the type of calling object is different from the string, exception "Invalid addition" is thrown.
Otherwise, the calling object's whole and fraction value has been updated to add otherObject's whole and fraction value.
Return: 
*/
void Currency::add(Currency* otherObject) {
  
  if(this->getType() != otherObject->getType())
    throw "Invalid addition";

  *(this->whole) += *(otherObject->whole);
  *(this->fraction) += *(otherObject->fraction);

  this->normalize();

}

/*
This function subtracts the value of a currency of the same object to the value of a calling object.
Pre: otherObject - Pointer to an object of type Currency
Post: If otherObject's value is greater than calling object's value, or the types of the calling object and otherObject are different, exception "Invalid subtraction" is thrown.
The calling object's whole and fraction value has been updated to subtract otherObject's whole and fraction value.
Return:   
*/
void Currency::subtract(Currency* otherObject) {

  if((!(this->isGreater(otherObject)) && !(this->isEqual(otherObject))) || (this->getType() != otherObject->getType()))
    throw "Invalid subtraction"; 

  *(this->whole) -= *(otherObject->whole);
  *(this->fraction) -= *(otherObject->fraction);

  this->normalize();
}

/*
This function returns true if the value of an object of the same currency type is equal to the value of a calling object.
Pre: otherObject - Pointer to an object of type Currency
Post: true will be returned if value of otherObject and value of calling object are equal, otherwise false.
Return: true or false
*/
bool Currency::isEqual(Currency* otherObject) const {
  
  bool result = false;

  if((*(this->whole) == *(otherObject->whole)) && (*(this->fraction) == *(otherObject->fraction)))
    result = true;
  
  return result;

}

/*
This function returns true if the value of an object of the same currency type is greater than the value of calling object.
Pre: otherObject - Pointer to an object of the same Currency type
Post: true will be returned if value of otherObject is greater than the value of calling object, otherwise false.
Return: true or false
*/
bool Currency::isGreater(Currency* otherObject) const {
  
  bool result = false;

  if((*(this->whole) > *(otherObject->whole)))
    result = true;
  else if((*(this->fraction) > *(otherObject->fraction)))
    result = true;

  return result;

}

/* HIGHLIGHT: CHANGE ====================
    Instead of returning from this function, this function is changed to print directly to the console
==================== HIGHLIGHT: CHANGE */
/*
This function prints the value of the calling object (whole added to fraction which is divided by 100) to 2 decimal places then the currency type.
Pre: 
Post: The value is printed to a precision of 2 decimal points and the currency type is printed.
Return: 
*/
void Currency::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << getWhole() + (getFraction()/100.0) << " " << getType();
}

/*
This function normalizes the whole and the fraction parts of the value by carrying over any extra value from the fraction to the whole, and deducts from whole if fraction is under 0.
Pre:
Post: whole and fraction are altered accordingly so they correctly represent the value.
Return:
*/
void Currency::normalize() {

	if(*fraction >= 0) {
		int d = *fraction / 100;
		*whole += d;
		*fraction %= 100;
	} else {
		*fraction += 100;
		--*whole;
	}
  
}

/*
These setter functions either set the value of whole or the value of fraction to an integer.
Pre: value - integer which whole/fraction will be set to
Post: The int value of whole/fraction will have been set to value.
Return: 
*/
void Currency::setWhole(int value) {
  *(this->whole) = value;
}
void Currency::setFraction(int value) {
  *(this->fraction) = value;
}

/*
These getter functions either return the value of whole or the value of fraction as an integer.
Pre: 
Post: 
Return: whole/fraction accordingly
*/
int Currency::getWhole() const {
  return *whole;
}
int Currency::getFraction() const {
  return *fraction;
}

#endif