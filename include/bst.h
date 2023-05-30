// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int count;
    Node* left, * right;
  };
  Node* root;
  Node* addNode(Node* root, T value) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->left = root->right = nullptr;
      root->count = 1;
    } else if (value < root->value) {
      root->left = addNode(root->left, value);
    } else if (value > root->value) {
      root->right = addNode(root->right, value);
    } else {
      root->count += 1;
    }
    return root;
  }
  int heightTree(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int hleft = heightTree(root->left);
    int hrright = heightTree(root->right);
    if (hleft > hrright) {
      return hleft + 1;
    } else {
      return hrright + 1;
    }
  }
  int searchTree(Node* root, T value) {
    if (root == nullptr) {
      return 0;
    }
    while (true) {
      if (value > root->value) {
        root = root->right;
      } else if (value < root->value) {
        root = root->left;
      } else {
        return root->count;
      }
    }
  }
 public:
  BST(): root(nullptr) {}
  void add(T value) {
    root = addNode(root, value);
  }
  int depth() {
    return heightTree(root) - 1;
  }
  int search(T value) {
    return searchTree(root, value);
  }
};
#endif  // INCLUDE_BST_H_
