#include "union_find_sets.h"

UnionFindSets::UnionFindSets(int n) {
  parent.reserve(n + 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }
}

int UnionFindSets::find(int i) {
  if (parent[i] == i) {
    return i;
  }
  // 路径压缩
  return parent[i] = find(parent[i]);
}

void UnionFindSets::merge(int i, int j) {
  int parent_i = find(i);
  int parent_j = find(j);
  if (parent_i != parent_j) {
    parent[parent_i] = parent_j;
  }
}