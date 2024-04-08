#include <bits/stdc++.h>
using namespace std;

class AVLTree {
 public:
  struct Node {
    int val, height;
    Node *left, *right;
    Node(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
  };

  function<bool(int, int)> Comparer = less<int>();
  Node *root;

  AVLTree() : root(nullptr) {}

  int height(Node *node) { return node ? node->height : 0; }

  int balance(Node *node) { return height(node->left) - height(node->right); }

  void update(Node *node) {
    node->height = max(height(node->left), height(node->right)) + 1;
  }

  Node *rotate_left(Node *node) {
    Node *right = node->right;
    node->right = right->left;
    right->left = node;
    update(node);
    update(right);
    return right;
  }

  Node *rotate_right(Node *node) {
    Node *left = node->left;
    node->left = left->right;
    left->right = node;
    update(node);
    update(left);
    return left;
  }

  Node *insert(Node *node, int val) {
    if (!node) return new Node(val);
    if (Comparer(val, node->val)) {
      node->left = insert(node->left, val);
    } else if (val > node->val) {
      node->right = insert(node->right, val);
    } else {
      return node;
    }
    update(node);
    if (balance(node) > 1) {
      if (balance(node->left) < 0) {
        node->left = rotate_left(node->left);
      }
      return rotate_right(node);
    }
    if (balance(node) < -1) {
      if (balance(node->right) > 0) {
        node->right = rotate_right(node->right);
      }
      return rotate_left(node);
    }
    return node;
  }

  Node *erase(Node *node, int val) {
    if (!node) return nullptr;
    if (val < node->val) {
      node->left = erase(node->left, val);
    } else if (val > node->val) {
      node->right = erase(node->right, val);
    } else {
      if (!node->left || !node->right) {
        Node *temp = node->left ? node->left : node->right;
        delete node;
        return temp;
      }
      Node *temp = node->right;
      while (temp->left) temp = temp->left;
      node->val = temp->val;
      node->right = erase(node->right, temp->val);
    }
    update(node);
    if (balance(node) > 1) {
      if (balance(node->left) < 0) {
        node->left = rotate_left(node->left);
      }
      return rotate_right(node);
    }
    if (balance(node) < -1) {
      if (balance(node->right) > 0) {
        node->right = rotate_right(node->right);
      }
      return rotate_left(node);
    }
    return node;
  }

  void insert(int val) { root = insert(root, val); }

  void erase(int val) { root = erase(root, val); }

  bool find(int val) {
    Node *node = root;
    while (node) {
      if (val < node->val) {
        node = node->left;
      } else if (val > node->val) {
        node = node->right;
      } else {
        return true;
      }
    }
    return false;
  }
};