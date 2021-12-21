/*============
Lab 3 - Lists, Stacks and Queues
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a singly-linked list and derivative ADTs (that use FIFO and LIFO) to practice with linear lists.
============*/
#ifndef QUEUE_H
#define QUEUE_H

#include "SinglyLinkedList.h"

class Queue : protected SinglyLinkedList {

  public:

    Queue();
    Queue(LinkNode *start);

    void enQueue(Currency* newCurrency);
    Currency* deQueue();
    Currency* peekFront();
    Currency* peekRear();
    void printQueue();

    ~Queue();

};

/*
This constructor calls the base constructor SinglyLinkedList().
Pre: 
Post: SinglyLinkedList() will be called to set count = new int(0), start = nullptr, and end = nullptr;
Return: 
*/
Queue::Queue() : SinglyLinkedList() {};

/*
This constructor calls the base constructor SinglyLinkedList(start) to create a Queue with start as its one LinkNode.
Pre: start - Pointer to LinkNode which will become the front of a new Queue
Post: SinglyLinkedList(start) will be called to set count = new int(1), this->start = start, and end = start
Return: 
*/
Queue::Queue(LinkNode *start) : SinglyLinkedList(start) {};

/*
This function adds a LinkNode containing the Currency pointer newCurrency to the end of the queue. 
Pre: newCurrency - Pointer to object of type Currency
Post: LinkNode containing newCurrency is added to the end of the queue. count increases by one. 
Return: 
*/
void Queue::enQueue(Currency* newCurrency) {
  this->addCurrency(newCurrency, this->countCurrency());
}

/*
This function removes the LinkNode at the front of the queue and returns the data of this node as a Currency pointer.
Pre: 
Post: The LinkNode at the front of the queue will have been removed. count will decrease by one. If queue is empty, exception "Array is empty" is thrown.
Return: Currency pointer which used to be at the top of the queue before being removed. (unless queue is empty, then nothing returned)
*/
Currency* Queue::deQueue() {
  return this->removeCurrency(0);
}

/*
This function returns a copy of the Currency pointer at the front of the queue.
Pre: 
Post: 
Return: Copy of Currency pointer contained in the LinkNode at the front of the queue.
*/
Currency* Queue::peekFront() {
  Currency* frontCurrency = this->getCurrency(0)->copyCurrency();
  return frontCurrency;
}

/*
This function returns a copy of the Currency pointer at the rear of the queue.
Pre: 
Post: 
Return: Copy of Currency pointer contained in the LinkNode at the rear of the queue.
*/
Currency* Queue::peekRear() {
  Currency* rearCurrency = this->getCurrency(countCurrency()-1)->copyCurrency();
  return rearCurrency;
}

/*
This function prints the contents of the queue from front to end, tab spaced.
Pre: 
Post: The contents of the queue (the values held in the Currency pointers) from front to end are printed with tabs in between.
Return:
*/
void Queue::printQueue() {
  this->printList();
}

// Destructor
Queue::~Queue() {};

#endif