// https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
 public:
  bool is_end = false;
  unordered_map<char, TrieNode*> children;
};

class Trie {
 public:
  TrieNode* root;
  int size = 0;
  Trie() { root = new TrieNode(); }
  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->children.count(c)) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->is_end = true;
    size++;
  }
  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->children.count(c)) return false;
      node = node->children[c];
    }
    return node->is_end;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      if (!node->children.count(c)) return false;
      node = node->children[c];
    }
    return true;
  }
};
