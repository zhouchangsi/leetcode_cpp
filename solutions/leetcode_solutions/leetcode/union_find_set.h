#pragma once
#include <vector>

namespace leetcode {

class UnionFindSets
{
public:
  std::vector<int> parent;
  UnionFindSets(int n)
  {
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
  }
  int find(int i)
  {
    if (parent[i] == i) {
      return i;
    }
    return parent[i] = find(parent[i]); // assign parent[i] for path compression
  }
  void merge(int i, int j)
  {
    int parent_i = find(i);
    int parent_j = find(j);
    if (parent_i != parent_j) {
      parent[parent_i] = parent_j;
    }
  }
};

};