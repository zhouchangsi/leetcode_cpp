/**
 * https://leetcode.cn/problems/course-schedule-ii/description/
 * https://og7kl7g6h8.feishu.cn/docx/NVzxdJ3uwoMMKWxFef7cW1uDnuh
 */
#include <bits/stdc++.h>
using namespace std;

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