#include "tree.h"
#include <iostream>
using namespace std;

int main() {
  Tree tree;
  Tree newTree;

  for (int i = 0; i < 20; i++) {
    int value = (rand() % 40);
    tree.insertNode(tree.getRoot(), value);
  }

  int input = 0;

  while (input != 6) {
    cout << "Please select an option:\n"
         << "1 : Insert a new node\n"
         << "2 : Print Tree\n"
         << "3 : Count The Number of Nodes\n"
         << "4 : Count the Number of Leaves\n"
         << "5 : Generate a New Tree (with double its previous values)\n"
         << "6 : Exit:" << endl;
    cin >> input;
    if (input == 1) {
      int newValue;
      cout << "Enter the value to insert: ";
      cin >> newValue;
      tree.insertNode(tree.getRoot(), newValue);
    } 
    else if (input == 2) {
      tree.printTree();

    } 
    else if (input == 3) {
      int numofnodes = tree.NumOfNodes(tree.getRoot());
      cout << "Number of nodes: " << numofnodes << "\n\n";

    } 
    else if (input == 4) {
      int leafcount = tree.countLeaves(tree.getRoot());
      cout << "Number of Leaves: " << leafcount << "\n\n";
      ;
  
    }
    else if (input == 5) {
      tree.copyTree(tree.getRoot(), newTree.getRoot());
      newTree.printTree();
    } else {
      cout << "Invalid option, please select one of the listed options\n";
    }
  }
}
