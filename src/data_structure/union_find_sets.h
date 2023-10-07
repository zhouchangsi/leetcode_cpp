#pragma once

#include <vector>

class UnionFindSets {
 public:
  std::vector<int> parent;
  UnionFindSets(int n);
  int find(int i);
  void merge(int i, int j);
};
