#pragma once

#include <gtest/gtest.h>

#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>  // IWYU pragma: export

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListTest {
 public:
  static bool is_equals(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val != l2->val) {
        return false;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
  }
};

class UnionFindSets {
 public:
  std::vector<int> parent;

  UnionFindSets(int n) {
    parent.reserve(n + 1);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
  }

  int find(int i) {
    if (parent[i] == i) {
      return i;
    }
    // 路径压缩
    return parent[i] = find(parent[i]);
  }

  void merge(int i, int j) {
    int parent_i = find(i);
    int parent_j = find(j);
    if (parent_i != parent_j) {
      parent[parent_i] = parent_j;
    }
  }
};
