/*============
Lab 4 - Binary Search Trees
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a binary search tree and apply multiple operations to practice with binary trees.
============*/
#ifndef BSTNODE_H
#define BSTNODE_H

#include "Currency.h"
#include "Dollar.h"
#include "BST.h"
#include "BSTNode.h"

class BSTNode {
  private:
    // Data
    Currency* data;

    // Pointers
    BSTNode* right;
    BSTNode* left;

  public:

    // Constructors
    BSTNode();
    BSTNode(Currency* data, BSTNode* right, BSTNode* left);
    ~BSTNode();

    // Getters and Setters
    Currency* getData();
    void setData(Currency* input);
    BSTNode* getRight();
    BSTNode* getLeft();
    void setRight(BSTNode* right);
    void setLeft(BSTNode* left);
};

/*
This constructor sets the member variables data, right, and left to nullptr.
Pre: 
Post: this->data, this->left, and this->right are initialized.
Return:
*/
BSTNode::BSTNode() {
  data = nullptr;
  right = nullptr;
  left = nullptr;
}

/*
This constructor sets the member variables data, right, and left passed parameters.
Pre: 
Post: this->right, this->data, and this->left are initialized.
Return:
*/
BSTNode::BSTNode(Currency* data, BSTNode* right, BSTNode* left) {
  this->data = data;
  this->right = right;
  this->left = left;
}

// Destructor to delete data, right, left
BSTNode::~BSTNode() {
  delete data;
  delete right;
  delete left;
}

/*
These getter functions return the member variable data/right/left
Pre:
Post: 
Return: data/right/left
*/
Currency* BSTNode::getData() {
  return data;
}
BSTNode* BSTNode::getRight() {
  return right;
}
BSTNode* BSTNode::getLeft() {
  return left;
}

/*
This setter function sets the member variable data (a Currency pointer) to the passed parameter
Pre: input - Currency pointer which data will be set to
Post: data will be set to input
Return:
*/
void BSTNode::setData(Currency* input) {
  data = input;
}
/*
These setter functions set the member variable right/left (a BSTNode pointer) to the passed parameter
Pre: inptRight/inptLeft - BSTNode pointer to one of the next nodes in tree (to left/right)
Post: right/left is set to inptRight/inptLeft
Return: 
*/
void BSTNode::setRight(BSTNode* inptRight) {
  this->right = inptRight;
}
void BSTNode::setLeft(BSTNode* inptLeft) {
  this->left = inptLeft;
}

#endif