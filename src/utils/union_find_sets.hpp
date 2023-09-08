#pragma once

#include <vector>

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
