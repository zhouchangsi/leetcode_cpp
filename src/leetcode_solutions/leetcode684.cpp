#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFindSets ufs(n);

    for (int i = 0; i < n; i++) {
      auto edge = edges[i];
      int node1 = edge[0], node2 = edge[1];
      if (ufs.find(node1) == ufs.find(node2)) {
        return edge;
      }
      ufs.merge(node1, node2);
    }
    return vector<int>();
  }
};

TEST(leetcode648, solution) {
  Solution s;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> expect = {2, 3};
  EXPECT_EQ(s.findRedundantConnection(edges), expect);
}