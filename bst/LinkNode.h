/*============
Lab 4 - Binary Search Trees
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a binary search tree and apply multiple operations to practice with binary trees.
============*/
/* HIGHLIGHT: CHANGE ====================
   We have 2 private attributes which also act as data in this case. These are used to store the left and right pointers of BSTNodes
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have 2 sets of setter and getter functions which set and get the right and left attributes respectively
==================== HIGHLIGHT: CHANGE */
#ifndef LINKNODE_H
#define LINKNODE_H

#include "Currency.h"
#include "BSTNode.h"

class LinkNode {

  private:
    // data
    Currency* data;

    /* HIGHLIGHT: CHANGE ====================
      We have 2 private attributes which also act as data in this case. These are used to store the left and right pointers of BSTNodes
    ==================== HIGHLIGHT: CHANGE */
    BSTNode* left;
    BSTNode* right;

    // pointer to next node
    LinkNode* next;
    
  public:
  
    LinkNode();
    ~LinkNode();
    LinkNode(Currency* data, LinkNode* next = nullptr);
    
    void setData(Currency* data);
    void setNext(LinkNode* next);

    Currency* getData();
    LinkNode* getNext();

    /* HIGHLIGHT: CHANGE ====================
      We have 2 sets of setter and getter functions which set and get the right and left attributes respectively
    ==================== HIGHLIGHT: CHANGE */
    void setRightData(BSTNode* right);
    void setLeftData(BSTNode* left);

    BSTNode* getRightData();
    BSTNode* getLeftData();

};

// Default Constructor
LinkNode::LinkNode() {
  this->data = nullptr;
  this->next = nullptr;
  right = nullptr;
  left = nullptr;
}

// Destructor
LinkNode::~LinkNode() {
  delete data;
  next = nullptr;
  delete right;
  delete left;
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
  right = nullptr;
  left = nullptr;
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

void LinkNode::setRightData(BSTNode* right) {
  this->right = right;
}

void LinkNode::setLeftData(BSTNode* left) {
  this->left = left;
}

BSTNode* LinkNode::getRightData() {
  return this->right;
}

BSTNode* LinkNode::getLeftData() {
  return this->left;
}

#endif