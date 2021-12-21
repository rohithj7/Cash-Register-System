/*============
Lab 5 - Hash Tables
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a hash table with quadratic probing and apply multiple operations to practice with hash tables.
============*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Currency.h"
#include "Dollar.h"

class HashTable {

private:

    Currency** data;
    int tableSize;
    int count; //# of elements currently in the array
    int prevCollisions;

    int hashFunction(Currency* inptCurr);
    int quadraticProbe(int initBucket, int i);

public:
    //Currency** data;
    HashTable();
    HashTable(int numElements);
    ~HashTable();
    bool insert(Currency* inptCurr);
    int search(Currency* inptCurr);
    double loadFactor();

    int getCollisions();
    int getCount();

    /** HIGHLIGHT: Change from previous version
      * Declaration of printTable function
    **/
    void printTable();

};

HashTable::HashTable() {
    data = nullptr;
    tableSize = 0;
    count = 0;
    prevCollisions = 0;
}

HashTable::HashTable(int numElements) {
    tableSize = numElements;
    data = new Currency * [tableSize];
    for (int i = 0; i < tableSize; i++) {
        data[i] = nullptr;
    }
    count = 0;
    prevCollisions = 0;
}

HashTable::~HashTable() {
    for(int i = 0; i < count; i++) {
        delete data[i];
    }
    delete[] data;
}

int HashTable::hashFunction(Currency* inptCurr) {
    const int m = 2, n = 3;
    return (m * inptCurr->getWhole() + n * inptCurr->getFraction()) % tableSize;
}

bool HashTable::insert(Currency* inptCurr) {

    if (count > tableSize || data == nullptr)
        return false;

    int orig = hashFunction(inptCurr);
    int i = 0;

    while (data[quadraticProbe(orig, i)]!= nullptr && i < tableSize) {
        i++;
        prevCollisions++;
    }
    if (data[quadraticProbe(orig, i)] == nullptr) {
        data[quadraticProbe(orig, i)] = inptCurr;
        count++;
        return true;
    }

    return false;

}

int HashTable::search(Currency* inptCurr) {

    if (data == nullptr)
        return -1;

    int orig = hashFunction(inptCurr);
    int i = 0;
    while (data[quadraticProbe(orig, i)] != nullptr) {
        if (data[quadraticProbe(orig, i)]->isEqual(inptCurr)) {
            return quadraticProbe(orig, i);
        }
        i++;
    }
    return -2;
}

/** HIGHLIGHT: Change from previous version
  * This function prints all the contents of the Hash Table
**/
void HashTable::printTable() {
  std::cout << "\n";
  for (int i = 0; i < tableSize; i++) {
    std::cout << "hashTable[" << i << "]: ";
    if (this->data[i] != nullptr) {
      this->data[i]->print();
    } else {
      std::cout << "null";
    }
    std::cout << std::endl;
  }
}

int HashTable::quadraticProbe(int initBucket, int i) {
    int c1 = 1, c2 = 1;
    return (initBucket + c1 * i + c2 * (i * i)) % tableSize;
}

double HashTable::loadFactor() {
    return count * 1.0 / tableSize;
}

int HashTable::getCollisions() {
    return prevCollisions;
}

int HashTable::getCount() {
    return count;
}

#endif