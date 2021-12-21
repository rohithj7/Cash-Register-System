/*============
Lab 3 - Lists, Stacks and Queues
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a singly-linked list and derivative ADTs (that use FIFO and LIFO) to practice with linear lists.
============*/
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Dollar.h"

using namespace std;
const int arraySize = 20;

int main() {
  cout << "Welcome to the Dollar Manipulation Program using ADTs!\nAuthors: Katelyn Nguyen, Rohith J Iyengar\n";
  double valArray[] = {57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21, 345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00};
  Currency *moneyArray[arraySize];
  for (int i=0; i<arraySize; i++) {
    moneyArray[i] = new Dollar(valArray[i]);
  }

  SinglyLinkedList listObj;
  Stack stackObj;
  Queue queueObj;
  
  try {
    
    // LINKED LIST
    for (int i = 6, j = 0; i >= 0; i--, j++) {
      listObj.addCurrency(moneyArray[i]->copyCurrency(), j);
    }

    // Searching for 2 currencies and printing results
    Currency *search1 = new Dollar(87.43);
    Currency *search2 = new Dollar(44.56);

    int index1 = listObj.findCurrency(search1);
    int index2 = listObj.findCurrency(search2);

    if (index1 != -1) {
      cout << "\n$87.43 found at index " << index1 << endl;
    } else {
      cout << "$87.43 not found." << endl;
    }

    if(index2 != -1) {
      cout << "$44.56 found at index " << index2 << endl;
    } else {
      cout << "$44.56 not found." << endl;
    }

    // Removing 2 currencies from the list
    Currency *removeDollar = new Dollar(111.22);
    listObj.removeCurrency(removeDollar);
    listObj.removeCurrency(2);

    // Printing the list
    listObj.printList();
    
    // Adding 4 currencies and removing 2
    for (int i=9; i<=12; i++) {
      listObj.addCurrency(moneyArray[i]->copyCurrency(), i%5);
    }
    listObj.removeCurrency(listObj.countCurrency() % 6);
    listObj.removeCurrency(listObj.countCurrency() / 7);

    // Printing the list
    listObj.printList();

    // Clean up
    delete search1;
    delete search2;
    delete removeDollar;
    search1 = nullptr;
    search2 = nullptr;
    removeDollar = nullptr;

    // STACK
    for (int i = 13; i <= 19; i++) {
      stackObj.push(moneyArray[i]->copyCurrency());
    }
    
    // Peeking top currency and printing it
    Currency *frontDollar = stackObj.peek();
    cout << "\nPeek = ";
    frontDollar->print();
    cout << endl;

    // Popping 3 objects from the stack
    for (int i=0; i<3; i++) {
      stackObj.pop();
    }

    // Printing the stack
    stackObj.printStack();

    // Pushing 5 new objects into the stack
    for (int i=0; i<=4; i++) {
      stackObj.push(moneyArray[i]->copyCurrency());
    }
    
    // Popping twice in succession
    stackObj.pop();
    stackObj.pop();

    // Printing the stack
    stackObj.printStack();

    // QUEUE
    for (int i=5; i<=17; i+=2) {
      queueObj.enQueue(moneyArray[i]->copyCurrency());
    }

    // Peeking front and rear and printing it
    cout << "\nPeek Front: ";
    queueObj.peekFront()->print();
    cout << endl << "Peek Rear: ";
    queueObj.peekRear()->print();
    cout << endl;

    // De-queueing twice in succession
    queueObj.deQueue();
    queueObj.deQueue();

    // Printing the queue
    queueObj.printQueue();

    // En-queueing 5 objects into the queue
    for (int i=10; i<=14; i++) {
      queueObj.enQueue(moneyArray[i]->copyCurrency());
    }

    // De-queueing 3 objects in succession
    for (int i=0; i<3; i++) {
      queueObj.deQueue();
    }

    // Printing the stack and exit message
    queueObj.printQueue();
    cout << "\nDone!" << endl;

  }
  catch (const char* errorMsg) {
    cout << errorMsg << endl;
  }

  //Deallocate double array
  for (int i=0; i<arraySize; i++) {
    delete moneyArray[i];
  }

  // Exit message
  cout << "*beep* Thank you for using our program!\n";

  return 0;

}