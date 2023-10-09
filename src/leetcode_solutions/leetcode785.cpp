#include <gtest/gtest.h>
// #include "leetcode.h"

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
      if (color[i] == -1) {
        if (!dfs(graph, color, i, 0))
          return false;
      }
    }
    return true;
  }

  bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
    if (color[node] != -1)
      return color[node] == c;
    color[node] = c;
    for (int next : graph[node]) {
      if (!dfs(graph, color, next, 1 - c))
        return false;
    }
    return true;
  }
};

TEST(leetcode785, solution) {
  vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  Solution solution;
  bool res = solution.isBipartite(graph);
  EXPECT_EQ(res, true);
}

TEST(leetcode785, case2) {
  vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  Solution solution;
  bool res = solution.isBipartite(graph);
  EXPECT_EQ(res, false);
}