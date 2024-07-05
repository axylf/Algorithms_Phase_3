#include <iostream>
#include "tree.h"
using namespace std;

//Default constructor
Node::Node() {
  this->data = 0;
  this->left = NULL;
  this->right = NULL;
}
// Parameter constructor #1
Node::Node(int data) {
  this->data = data;
  this->left = NULL;
  this->right = NULL;
}

// Parameter constructor #2
Node::Node(int data, Node* left, Node* right) {
  this->data = data;
  this->left = left;
  this->right = right;
}