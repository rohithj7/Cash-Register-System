/*============
Lab 3 - Lists, Stacks and Queues
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a singly-linked list and derivative ADTs (that use FIFO and LIFO) to practice with linear lists.
============*/
#ifndef LINKNODE_H
#define LINKNODE_H

#include "Currency.h"

class LinkNode {

  private:
    Currency* data;
    LinkNode* next;

  public:
  
    LinkNode();
    ~LinkNode();
    LinkNode(Currency* data, LinkNode* next = nullptr);
    
    Currency* getData();
    LinkNode* getNext();

    void setData(Currency* data);
    void setNext(LinkNode* next);

};

LinkNode::LinkNode() {
  this->data = nullptr;
  this->next = nullptr;
}

LinkNode::~LinkNode() {
  delete data;
  next = nullptr;
}

/*
This constructor sets the member variables data and next to the parameters (next is nullptr by default).
Pre: data - Pointer to obj of type Currency
  next - Pointer to LinkNode
Post: this->data is set to data and this->next is set to next.
Return:
*/
LinkNode::LinkNode(Currency* data, LinkNode* next) {
  this->data = data;
  this->next = next;
}

/*
These getter functions return data/next.
Pre: 
Post: 
Return: The private member variable data/next
*/
Currency* LinkNode::getData() {
  return (this->data);
}
LinkNode* LinkNode::getNext() {
  return (this->next);
}

/*
This setter function sets data to the parameter.
Pre: data - Currency pointer
Post: this->data is set to data.
Return:
*/
void LinkNode::setData(Currency* data) {
  this->data = data;
}

/*
This setter function sets next to the parameter.
Pre: next - LinkNode pointer
Post: this->next is set to next.
Return:
*/
void LinkNode::setNext(LinkNode* next) {
  this->next = next;
}

#endif