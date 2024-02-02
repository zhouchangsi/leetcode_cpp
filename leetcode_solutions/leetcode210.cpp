#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 1. build graph
    vector<int> in_degree(numCourses, 0);
    vector<vector<int>> graph(numCourses, vector<int>());
    for (auto& edge : prerequisites) {
      int to = edge[0], from = edge[1];
      graph[from].push_back(to);
      ++in_degree[to];
    }

    // 2. topological sort
    queue<int> nodes_without_entrances;
    for (int i = 0; i < numCourses; ++i) {
      if (in_degree[i] == 0) {
        nodes_without_entrances.push(i);
      }
    }
    vector<int> sorted;
    while (!nodes_without_entrances.empty()) {
      int from = nodes_without_entrances.front();
      nodes_without_entrances.pop();
      sorted.push_back(from);
      for (auto& to : graph[from]) {
        in_degree[to]--;
        if (in_degree[to] == 0) {
          nodes_without_entrances.push(to);
        }
      }
    }

    if (sorted.size() != numCourses) {
      return vector<int>();
    }

    return sorted;
  }
};

TEST(leetcode210, solution) {
  Solution solution;
  vector<vector<int>> prerequisites = {{1, 0}};
  vector<int> ans = solution.findOrder(2, prerequisites);
  vector<int> expected = {0, 1};
  EXPECT_EQ(ans, expected);
}
