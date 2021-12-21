/*============
Lab 3 - Lists, Stacks and Queues
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a singly-linked list and derivative ADTs (that use FIFO and LIFO) to practice with linear lists.
============*/
#ifndef STACK_H
#define STACK_H

#include "SinglyLinkedList.h"

class Stack : protected SinglyLinkedList {

  public:

    Stack();
    Stack(LinkNode *start);

    void push(Currency* inptCurrency);
    Currency* pop();
    Currency* peek();
    void printStack();

    ~Stack();

};

Stack::Stack() : SinglyLinkedList() {};

/*
This constructor calls base constructor SinglyLinkedList(start) to create a Stack with start as its one LinkNode.
Pre: start - Pointer to LinkNode which will become the front of a new Stack
Post: SinglyLinkedList(start) will be called to set count = new int(1), this->start = start, and end = start
Return:
*/
Stack::Stack(LinkNode *start) : SinglyLinkedList(start) {}

/*
This function adds a LinkNode containing inptCurrency to the top of the stack.
Pre: inptCurrency - Pointer to data of type Currency which will be added to the top of the stack.
Post: LinkNode containing inptCurrency as its data will be at the top of the stack.
Return:
*/
void Stack::push(Currency* inptCurrency) {
  addCurrency(inptCurrency, 0);
}

/*
This function removes the LinkNode at the top of the Stack and returns the Currency pointer it contained.
Pre: 
Post: LinkNode at the top of the Stack was removed.
Return: Currency pointer that was contained in the LinkNode formerly at the top of the stack.
*/
Currency* Stack::pop() {
  Currency* endCurrency = this->getCurrency(0);
  this->removeCurrency(0);
  return endCurrency;
}

/*
This function returns a copy of the Currency pointer at the top of the stack
Pre: 
Post:
Return: Copy of Currency pointer contained in the LinkNode at the top of the stack.
*/
Currency* Stack::peek() {
  return getCurrency(0)->copyCurrency();
}

/*
This function prints the contents of the stack from top to bottom, tab spaced.
Pre: 
Post: The contents of the Stack (the values held in the Currency pointers) from top to bottom are printed with tabs in between.
Return:
*/
void Stack::printStack() {
  printList();
}

// Destructor
Stack::~Stack() {}

#endif