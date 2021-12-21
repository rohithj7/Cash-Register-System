/*============
Lab 4 - Binary Search Trees
Names: Katelyn Nguyen, Rohith J Iyengar
Purpose: Create a binary search tree and apply multiple operations to practice with binary trees.
============*/
/* ALL CHANGES IN LAB 4 */
/* HIGHLIGHT: CHANGE ====================
   We added an overloaded print function which prints the Currency data and type to the passed output file. 
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have 2 private attributes which also act as data in this case. These are used to store the left and right pointers of BSTNodes
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have 2 sets of setter and getter functions which set and get the right and left attributes respectively
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   The enQueue function is changed to also take in right and left attributes to set to the attributes of linknode via the singly linked list
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have a new addBST function which sets the left and right attribute paremeter to the linknode attributes
==================== HIGHLIGHT: CHANGE */
/* HIGHLIGHT: CHANGE ====================
   We have a new removeBST function which removes a node and returns a BSTNode with left and right attributes attached
==================== HIGHLIGHT: CHANGE */
/* ALL CHANGES IN LAB 4 */

#include <iostream>
#include <fstream>
using namespace std;

#include "BST.h"
#include "BSTNode.h"
#include "Currency.h"
#include "Dollar.h"

int main() {

  BSTNode *treeNode = new BSTNode;
  BSTNode *treeRoot = new BSTNode;
  BST *tree = new BST;

  const double treeData[20] = {57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21, 345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00};
  
  for (int i = 0; i < 20; i++) {
    treeNode->setData(new Dollar(treeData[i]));
    tree->insert(treeNode);
  }

  ofstream outf;
  outf.open("output.txt");
  if (outf.fail()) {
    throw "File could not open";
  }
  tree->print(outf);

  cout << "\nType '1 <number>' to ADD that data to the tree.\nType '2 <number>' to SEARCH for that data.\nType '3 <number>' to DELETE that data.\nType '4' to PRINT the data in the BST to the screen and output file.\nType '0' to exit the program.\n\n";

  char choice;
  do {
    double inptNum = 0;
    try {
      cin >> choice;
      if (!isdigit(choice)) {
        throw "ERROR: A number was not entered";
      }

      if (choice == '1' || choice == '2' || choice == '3') {
        cin >> inptNum;
        if (inptNum < 0) {
          throw "ERROR: Invalid number entered";
        }
      }
        
      if (choice == '1') {
        BSTNode* userNode = new BSTNode;
        userNode->setData(new Dollar(inptNum));
        tree->insert(userNode);
        cout << "Number " << inptNum << " was added" << endl;
      } 
      else if (choice == '2') {
        BSTNode* nodeData = tree->search(tree->getRoot(), new Dollar(inptNum));
          if (nodeData != nullptr) {
            nodeData->getData()->print();
            cout << "- found.\n";
          } 
          else {
            cout << inptNum << " not found.\n";
          }
        } 
        else if (choice == '3') {
          if (tree->BSTdelete(tree->getRoot(), new Dollar(inptNum))) {
            cout << "Delete function called, check tree.\n";
          }
        } 
        else if (choice == '4') {
          outf << "\n";
          tree->print(outf);
        } 
        else if (choice == '0') {
          outf << "\n";
          tree->print(outf);
        }
        else {
          throw "ERROR: Invalid choice";
        }
    
    } catch (const char* errorMsg) {
      cout << errorMsg << ", ignoring choice " << choice << " ";
      outf << endl << errorMsg << ", ignoring choice " << choice << endl;
      if (inptNum != 0) {
        cout << "(data number " << inptNum << ")" << endl;
        outf << "(data number " << inptNum <<  ")" << endl;
      } else {
        cout << endl;
      }
    }
    cout << endl;
    outf << endl << endl;
  } while (choice != '0');
  
  outf.close();
  return 0;
}