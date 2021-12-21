/*============
Lab 5 - Hash Tables
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a hash table with quadratic probing and apply multiple operations to practice with hash tables.
============*/
#include <iostream>
#include <iomanip> //for setprecision
#include "Dollar.h"
#include "HashTable.h"
using namespace std;

int main() {
  HashTable *hashTable = new HashTable(29);
  const double tableData[20] = {57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21, 345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00};

  for (int i = 0; i < 20; i++) {
    hashTable->insert(new Dollar(tableData[i]));
  }

  cout << fixed << setprecision(2);
  cout << hashTable->getCount() << " data items have been loaded." << endl;
  cout << "Load Factor (rounded to hundredths): " << hashTable->loadFactor()*100 << "%" << endl;
  cout << "Collisions: " << hashTable->getCollisions() << endl;

  char userCont;
  do {
    try {
      userCont = 'n';
      double userData;
      cout << "\nPlease enter a Dollar to search for:\n";
      cin >> userData;
      if(userData < 0)
        throw "Invalid Number Entered";
      Currency* userDollar = new Dollar(userData);
      
      int index = hashTable->search(userDollar);
      if (index == -1) {
        throw "Invalid Array";
      } else if (index == -2) {
        throw "Invalid Data";
      } else {
        cout << "Index found: " << index << endl;
      }
    } catch(const char* msg) {
        cout << msg << endl;
    }
    cout << "Type 'y' to search for another Dollar. Type 'n' to end the program.\n";
    cin >> userCont;
  } while(userCont == 'y' || userCont == 'Y');

  /** HIGHLIGHT: Change from previous version
  * This statement calls the printTable function which prints all the elements of 
  * the hash table
  **/
  hashTable->printTable();

  delete hashTable;
  return 0;
} 