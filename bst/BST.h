/*============
Lab 4 - Binary Search Trees
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a binary search tree and apply multiple operations to practice with binary trees.
============*/
#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "SinglyLinkedList.h"
#include "Queue.h"

class BST {
  private:
    // Data
    BSTNode* root;

  public:

    // Constructor
    BST();

    // Basic functions
    BSTNode* search(BSTNode *root, Currency* targetKey);
    void insert(BSTNode *newNode);
    BSTNode* BSTdelete(BSTNode *root, Currency* deleteKey);
    void print(ostream& out);
    int count(BSTNode *root);
    bool isEmpty();
    void empty(BSTNode* root);
    
    // Traversal
    void breadthFirst(BSTNode *root, ostream& out);
    void inOrder(BSTNode *root, ostream& out);
    void preOrder(BSTNode *root, ostream& out);
    void postOrder(BSTNode *root, ostream& out);

    // Getter
    BSTNode* getRoot();

};

/*
This constructor sets the member variable root to nullptr.
Pre: 
Post: this->root is set to nullptr.
Return:
*/
BST::BST() {
  this->root = nullptr;
};

/*
This iterative function adds the new BSTNode to the binary search tree so that the tree maintains its ordering rules (internal nodes are greater than left child and less than or equal to right child, etc).
Pre: newNode - Pointer to newNode object to be added to the tree
Post: newNode will have been added to the binary search tree at the proper location.
Return: 
*/
void BST::insert(BSTNode *newNode) {

  if (root == nullptr) {

    root = new BSTNode();
    root->setData(newNode->getData()->copyCurrency());

  } else {

    BSTNode* curNode = root;
    
    while (curNode != nullptr) {

      if (newNode->getData()->isGreater(curNode->getData()) || newNode->getData()->isEqual(curNode->getData())) {
        if (curNode->getRight() == nullptr) {
          curNode->setRight(new BSTNode());
          curNode->getRight()->setData(newNode->getData()->copyCurrency());
          curNode = nullptr;
        }
        else {
          curNode = (curNode->getRight());
        }

      }
      else {
        if (curNode->getLeft() == nullptr) {
          curNode->setLeft(new BSTNode());
          curNode->getLeft()->setData(newNode->getData()->copyCurrency());
          curNode = nullptr;
        }
        else {
          curNode = curNode->getLeft();
        }
      }
    }
  }
}

/*
This getter function returns member variable root
Pre: 
Post:
Return: root - Pointer to BSTNode at the top of the tree
*/
BSTNode* BST::getRoot() {
  return this->root;
}

/*
This recursive function searches for a currency target key and returns the node containing that key
Pre: root - a pointer to a BST node of the tree at which to begin search
     targetKey - currency to search for
Post:
Return: 1. nullptr if targetkey not found, else 2. root - node containing search key
*/
BSTNode* BST::search(BSTNode *root, Currency* targetKey) {

  if(this->isEmpty() || root == nullptr)
    return nullptr;
  
  if(root->getData()->isGreater(targetKey)) {
    return search(root->getLeft(), targetKey);
  } else if(targetKey->isGreater(root->getData())) {
    return search(root->getRight(), targetKey);
  } else {
    return root;
  }

}

/*
This function returns true if the tree is empty
Pre:
Post:
Return: bool - true if tree is empty, false if tree is not empty
*/
bool BST::isEmpty() {

  if(this->root == nullptr)
    return true;
  return false;

}

/*
This iterative function is used to traverse breadth first across the nodes of a BST, printing each node to screen and output stream object 
Pre: root - the pointer to the BST node at the top of the binary search tree
     out - an ostream object to print to file
Post: Each node in the BST is printed to screen and output stream object, in breadth first order
Return:
*/
void BST::breadthFirst(BSTNode *root, ostream& out) {

  BSTNode *currentNode = new BSTNode;
  Queue *queueObj = new Queue;

  currentNode = root;
  while(currentNode != nullptr) {

    currentNode->getData()->print();
    currentNode->getData()->print(out);
    if(currentNode->getLeft() != nullptr) {
      BSTNode* temp = currentNode->getLeft();
      queueObj->enQueue(temp->getData(), temp->getRight(), temp->getLeft());
    }
    if(currentNode->getRight() != nullptr) {
      BSTNode* temp = currentNode->getRight();
      queueObj->enQueue(temp->getData(), temp->getRight(), temp->getLeft());
    }

    if (!(queueObj->isQueueEmpty())) {
      currentNode = queueObj->deQueue();
    } else {
      currentNode = nullptr;
    }
    
  }

  delete queueObj;
  queueObj = nullptr;

}

/*
This recursive function traverses a BST in inorder, printing each node to screen and file 
Pre: root - a pointer to a BST node of the tree at which to start traversal from
     out - an ostream object to print to file
Post: Each node in the BST is printed to screen and output stream object, in inorder order
Return:
*/
void BST::inOrder(BSTNode *root, ostream& out) {

  if (root != nullptr) {

    inOrder(root->getLeft(), out);
    root->getData()->print();
    root->getData()->print(out);
    inOrder(root->getRight(), out);

  }

}

/*
This recursive function traverses a BST in pre-order, printing each node to screen and file 
Pre: root - a node of the tree (BSTNode) at which to start traversal from
     out - an ostream object to print to file
Post: Each node in the BST is printed to screen and output stream object, in pre-order
Return:
*/
void BST::preOrder(BSTNode *root, ostream& out) {

  if(root != nullptr) {

    root->getData()->print();
    root->getData()->print(out);
    preOrder(root->getLeft(), out);
    preOrder(root->getRight(), out);

  }

}

/*
This recursive function prints a BST in post-order
Pre: root - a node of the tree (BSTNode) at which to start traversal from
     out - an ostream object to print to file
Post: Each node in the BST is printed to screen and output stream object, in postorder
Return:
*/
void BST::postOrder(BSTNode *root, ostream& out) {

  if(root != nullptr) {

    preOrder(root->getLeft(), out);
    preOrder(root->getRight(), out);
    root->getData()->print();
    root->getData()->print(out);

  }

}

/*
This recursive function deletes a tree node from the BST
Pre: root - a pointer to a BST node of the tree (originally top node of tree)
     deleteKey - currency to delete
Post: tree will not have deleteKey currency
Return: 1. nullptr if deletekey not found, else 2. root - BST node that was removed from tree
*/
BSTNode* BST::BSTdelete(BSTNode *root, Currency* deleteKey) {

  if (this->isEmpty() || root == nullptr)
    return nullptr;

  if (root->getData()->isGreater(deleteKey)) {
    root->setLeft(BSTdelete(root->getLeft(), deleteKey));
    return root;
  } 
  else if(deleteKey->isGreater(root->getData())) {
    root->setRight(BSTdelete(root->getRight(), deleteKey));
    return root;
  } 
  else {

    if (root->getLeft() == nullptr) {
      BSTNode* leftNull = root->getRight();
      return leftNull;
    } 
    else if (root->getRight() == nullptr) {
      BSTNode* rightNull = root->getLeft();
      return rightNull;
    }
    else {
      BSTNode *parent = root;

      BSTNode *deleteNodeSucc = root->getRight();  
      while (deleteNodeSucc->getLeft() != nullptr) {
        parent = deleteNodeSucc;
        deleteNodeSucc = deleteNodeSucc->getLeft();
      }

      if (parent != root)
        parent->setLeft(deleteNodeSucc->getRight());
      else
        parent->setRight(deleteNodeSucc->getRight());

      root->setData(deleteNodeSucc->getData());
  
      return root;
    }

  }

}

/*
This function prints all the nodes of the tree in breadth-first, in-order, pre-order, and post-order
Pre: out - an ostream object to print to file
Post: Prints all traversals to console and output stream object
Return: 
*/
void BST::print(ostream& out) {
  if (isEmpty()) {
    std::cout << "Empty tree\n";
    out << "Empty tree\n";
  } else {
    out << "BreadthFirst:\n";
    std::cout << "BreadthFirst:\n";
    breadthFirst(root, out);

    out << "\nInorder:\n";
    std::cout << "\nInorder:\n";
    inOrder(root, out);
    
    out << "\nPreorder:\n";
    std::cout << "\nPreorder:\n";
    preOrder(root, out);

    out << "\nPostOrder:\n";
    std::cout << "\nPostOrder:\n";
    postOrder(root, out);
    std::cout << endl;
    out << endl;
  }
}

/*
This recursive function counts and returns the count of all BST nodes
Pre: root - a BST node of the tree to start count from
Post: 
Return int - count of nodes in BST
*/
int BST::count(BSTNode *root) {

  int count = 0;

  if(root == nullptr)
    return count;
  
  count += 1 + this->count(root->getLeft()) + this->count(root->getRight());
  return count;

}

/*
This recursive function empties all the contents of the tree
Pre: root - a pointer to a BSTnode of the tree (originally top of tree)
Post: All nodes are removed from tree, root is nullptr
Return: 
*/
void BST::empty(BSTNode* root) {
  if (root != nullptr) {
    if (root->getLeft() != nullptr) {
    empty(root->getLeft());
    }
    if (root->getRight() != nullptr) {
    empty(root->getRight());
    }
    delete root;
  }
}

#endif