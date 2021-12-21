/*============
Lab 4 - Binary Search Trees
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a binary search tree and apply multiple operations to practice with binary trees.
============*/
/* HIGHLIGHT: CHANGE ====================
   We have a new addBST function which sets the left and right attribute paremeter to the linknode attributes
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have a new removeBST function which removes a node and returns a BSTNode with left and right attributes attached
==================== HIGHLIGHT: CHANGE */
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include "Currency.h"
#include "LinkNode.h"
#include "BSTNode.h"

class SinglyLinkedList {
  
  private:
    // Data
    int* count;

    // Pointers 
    LinkNode* start;
    LinkNode* end;

  public:
  
    // Constructors
    SinglyLinkedList();
    SinglyLinkedList(LinkNode *start);

    void addCurrency(Currency* newCurrency, int nodeIndex);

    /* HIGHLIGHT: CHANGE ====================
      We have a new addBST function which sets the left and right attribute paremeter to the linknode attributes
    ==================== HIGHLIGHT: CHANGE */
    void addBST(Currency* newCurrency, int nodeIndex, BSTNode* right, BSTNode* left);
    Currency* removeCurrency(Currency* inptCurrency);

    /* HIGHLIGHT: CHANGE ====================
      We have a new removeBST function which removes a node and returns a BSTNode with left and right attributes attached
    ==================== HIGHLIGHT: CHANGE */
    BSTNode* removeBST(int nodeIndex);
    int findCurrency(Currency* inptCurrency);
    Currency* getCurrency(int nodeIndex);
    void printList();
    bool isListEmpty();
    int countCurrency();

    virtual ~SinglyLinkedList();

};

// Constructor
SinglyLinkedList::SinglyLinkedList() {

  count = new int(0);
  start = nullptr;
  end = nullptr;

}

// Constructor with parameter for start of list
SinglyLinkedList::SinglyLinkedList(LinkNode *start) {

  this->count = new int(1);
  this->start = start;
  this->end = start;

}

// Destructor
SinglyLinkedList::~SinglyLinkedList() {

  delete count;
  count = nullptr;
  LinkNode *discard = start;
  while (discard != nullptr) {
    start = discard->getNext();
    delete discard;
    discard = start;
  }
  
}

/*
This function adds the new currency object to the list at the specified index
Pre: newCurrency - The Currency* type object to be added to the list
     nodeIndex - The index position at which the object needs to be added
Post: count is increased by 1
Return: 
*/
void SinglyLinkedList::addCurrency(Currency* newCurrency, int nodeIndex) {

  LinkNode* pNew = new LinkNode(newCurrency);
  if((nodeIndex > *count && nodeIndex != 0) || nodeIndex < 0) {
    throw "Invalid value entered";
  }

  if (this->isListEmpty()) {
    this->start = pNew;
    this->end = pNew;
  } else if (nodeIndex == 0) {
    pNew->setNext(start);
    start = pNew;
  } else if (nodeIndex == *count) {
    end->setNext(pNew);
    end = pNew;
  } else {
    int preIndex = 0;
    LinkNode* pPre = start;
    while (preIndex < nodeIndex-1) {
      pPre = pPre->getNext();
      preIndex++;
    }
    pNew->setNext(pPre->getNext());
    pPre->setNext(pNew);
  }

  *count += 1;

}

/*
This function adds the new currency object to the list at the specified index along with setting the linknode attributes to the parameters
Pre: newCurrency - The Currency* type object to be added to the list
     nodeIndex - The index position at which the object needs to be added
     right - BSTNode type object which holds the link to right node
     left - BSTNode type object which holds the link to left node
Post: count is increased by 1
Return: 
*/
void SinglyLinkedList::addBST(Currency* newCurrency, int nodeIndex, BSTNode* right, BSTNode* left) {

  LinkNode* pNew = new LinkNode(newCurrency);
  if((nodeIndex > *count && nodeIndex != 0) || nodeIndex < 0) {
    throw "Invalid value entered";
  }

  if (this->isListEmpty()) {
    this->start = pNew;
    this->end = pNew;
  } else if (nodeIndex == 0) {
    pNew->setNext(start);
    start = pNew;
  } else if (nodeIndex == *count) {
    end->setNext(pNew);
    end = pNew;
  } else {
    int preIndex = 0;
    LinkNode* pPre = start;
    while (preIndex < nodeIndex-1) {
      pPre = pPre->getNext();
      preIndex++;
    }
    pNew->setNext(pPre->getNext());
    pPre->setNext(pNew);
  }

  pNew->setRightData(right);
  pNew->setLeftData(left);

  *count += 1;

}

/*
This function removes the specified input Currency* object from the list
Pre: inptCurrency - The Currency* type object to be removed from the list
Post: count is decreased by 1
Return: deleted Currency* object
*/
Currency* SinglyLinkedList::removeCurrency(Currency* inptCurrency) {

  if (this->isListEmpty()) {
    throw "Array is empty. Invalid operation";
  }

  int pLocIndex = 0;
  LinkNode* pLoc = start;
  LinkNode* pPre = nullptr;

  while (!(pLoc->getData()->isEqual(inptCurrency))) {
    if (pLocIndex == *count) {
      throw "Cannot find value. Invalid value entered";
    } else {
      pPre = pLoc;
      pLoc = pLoc->getNext();
      pLocIndex++;
    }
  }

  if(*count == 1) {
    this->start = nullptr;
    this->end = nullptr;
  }
  else if (pLocIndex == 0) {
    this->start = pLoc->getNext();
  }
  else if (pLocIndex == *count - 1) {
    pPre->setNext(nullptr);
    this->end = pPre;
  }
  else {
    pPre->setNext(pLoc->getNext());
  }

  *count -= 1;

  Currency *returnData = pLoc->getData()->copyCurrency();
  delete pLoc;
  pLoc = nullptr;

  return returnData;

}

/*
This function removes the Currency* object at the specified index
Pre: nodeIndex - The position of the Currency* object which is to be removed from the list
Post: count is decreased by 1
Return: BSTNode* - the deleted currency along with the left and right attributes
*/
BSTNode* SinglyLinkedList::removeBST(int nodeIndex) {

  if(this->isListEmpty()) {
    throw "Array is empty. Invalid operation";
  } else if ((nodeIndex >= *count && nodeIndex != 0) || nodeIndex < 0) {
    throw "Invalid value entered";
  }

  int pLocIndex = 0;
  LinkNode* pPre = nullptr;
  LinkNode* pLoc = start;
  
  while (pLocIndex != nodeIndex) {
    pPre = pLoc;
    pLoc = pLoc->getNext();
    pLocIndex++;
  }

  if (*count == 1) {
    start = nullptr;
    end = nullptr;
  } 
  else if (pLocIndex == 0) {
    this->start = pLoc->getNext();
  } 
  else if (pLocIndex == *count - 1) {
    pPre->setNext(nullptr);
    this->end = pPre;
  } 
  else {
    pPre->setNext(pLoc->getNext());
  }

  *count -= 1;

  return new BSTNode(pLoc->getData(), pLoc->getRightData(), pLoc->getLeftData());

}

/*
This function finds the specified input Currency* object from the list
Pre: inptCurrency - The Currency* type object to be found in the list
Post: 
Return: index of specified Currency* object
*/
int SinglyLinkedList::findCurrency(Currency* inptCurrency) {

  int pLocIndex = 0;
  bool found = false;
  LinkNode* pLoc = start;

  while((pLocIndex < *(this->count)) && !found) {
    if(pLoc->getData()->isEqual(inptCurrency)) {
      found = true;
    } 
    else if ((pLocIndex == *(this->count) - 1) && !found) {
      pLocIndex = -1;
      found = true;
    }
    else {
      pLoc = pLoc->getNext();
      pLocIndex++;
    }  
  }

  return pLocIndex;

}

/*
This function finds and gets the Currency* object at a specified index from the list
Pre: nodeIndex - The index at which the Currency* object to be returned is located
Post: 
Return: Currency* object at the specified index
*/
Currency* SinglyLinkedList::getCurrency(int nodeIndex) {

  int pLocIndex = 0;
  LinkNode* pLoc = start;

  while (pLocIndex != nodeIndex) {
    if (pLocIndex == *count) {
      return nullptr;
    } else {
      pLoc = pLoc->getNext();
      pLocIndex++;
    }
  }

  return pLoc->getData()->copyCurrency();

}

/*
This function prints all the elements of the array with a tab space in between each element
Pre: 
Post: Prints a string with all string elements to the console
Return: 
*/
void SinglyLinkedList::printList() {

  LinkNode* pLoc;

  if(!isListEmpty()) {
    pLoc = start;
    for(int i = 0; i < *count; i++) {
      pLoc->getData()->print();
      std::cout << "\t";
      pLoc = pLoc->getNext();
    }
  } else {
    std::cout << "List is empty";
  }

  std::cout << std::endl;

}

/*
This function returns whether the list is empty or not
Pre:
Post:
Return: true or false
*/
bool SinglyLinkedList::isListEmpty() {

  if ((*count == 0) && (start == nullptr) && (end == nullptr))
    return true;
  else 
    return false;

}

/*
This function returns the count of elements in the list
Pre:
Post:
Return: count (int)
*/
int SinglyLinkedList::countCurrency() {
  return *(this->count);
}

#endif