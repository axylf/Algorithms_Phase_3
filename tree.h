#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

// A class for node data type
class Node {
public:
  int data;
  Node *left, *right;

  // Default constructor
  Node();
  // Parameter constructor #1
  Node(int data);
  // Parameter constructor #2
  Node(int data, Node *left, Node *right);
};

class Tree {
public:
  // Tree Data Structure

  // Default Constructor
  Tree() {
    root = NULL;
    r_child = root;
    l_child = root;
  };

  // Parameter constructor #1
  Tree(Node *x) {
    root = x;
    r_child = NULL;
    l_child = NULL;
  }

  void insertNode(Node *&root, int data) {
    if (!root) {
      root = new Node(data);
      numNodes++;
    } else {
      if (data < root->data) {
        insertNode(root->left, data);
      } else if (data > root->data) {
        insertNode(root->right, data);
      }
    }
  }

  void printTree() {
    int input = 0;
    while (input != 4) {
      cout << "\nSelect method to print out tree\n"
           << "\n1 for in-order"
           << "\n2 for post-order"
           << "\n3 for pre-order"
           << "\n4 to Exit\n";
      cin >> input;
    //
    
    if (input == 1) {
      inorder(root);
    }

    else if (input == 2) {
      postorder(root);
    }

    else if (input == 3) {
      preorder(root);
    } 
  }  
}

  void preorder(Node *head_ptr) {
    if (head_ptr == NULL) {
      return;
    }
    cout << head_ptr->data << " ";
    preorder(head_ptr->left);
    preorder(head_ptr->right);
  }

  void postorder(Node *head_ptr) {
    if (head_ptr == NULL) {
      return;
    }
    postorder(head_ptr->left);
    postorder(head_ptr->right);
    cout << head_ptr->data << " ";
  }

  void inorder(Node *head_ptr) {
    if (head_ptr == NULL) {
      return;
    }
    inorder(head_ptr->left);
    cout << head_ptr->data << " ";
    inorder(head_ptr->right);
  }

  int NumOfNodes(Node *root) { return numNodes; }

  int countLeaves(Node *root) {
    if (root == NULL)
      return 0;
    if (root->left == NULL && root->right == NULL)
      return 1;
    else
      return countLeaves(root->left) + countLeaves(root->right);
  }

  Node *&getRoot() { return root; }

  void copyTree(Node *&root1, Node *&root2) {
    if (root1) {
      root2 = new Node(root1->data * 2);
      copyTree(root1->left, root2->left);
      copyTree(root1->right, root2->right);
    }
  }

  Tree operator=(Tree &t) { // syntactic sugar
    Tree new_tree;
    copyTree(t.getRoot(), new_tree.getRoot());
    return new_tree;
  }

private:
  Node *root;
  Node *r_child;
  Node *l_child;

  int numNodes;
};