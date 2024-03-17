
/**
 * https://leetcode-cn.com/problems/parallel-courses/
 * https://leetcode.cn/problems/parallel-courses/solutions/150695/ping-xing-ke-cheng-by-leetcode-solution/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumSemesters(int N, vector<vector<int>>& relations) {
    vector<vector<int>> graph(N + 1);
    for (auto& relation : relations) {
      graph[relation[0]].push_back(relation[1]);
    }

    vector<int> visited(N + 1, 0);
    int maxLength = 1;
    for (int node = 1; node < N + 1; node++) {
      int length = dfs(node, graph, visited);
      // 我们遇到了一个环！
      if (length == -1) {
        return -1;
      }
      maxLength = max(length, maxLength);
    }
    return maxLength;
  }

 private:
  int dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    // 返回最长路（含）
    if (visited[node] != 0) {
      return visited[node];
    } else {
      // 标记为正在访问
      visited[node] = -1;
    }
    int maxLength = 1;
    for (auto& endNode : graph[node]) {
      int length = dfs(endNode, graph, visited);
      // 我们遇到了一个环！
      if (length == -1) {
        return -1;
      }
      maxLength = max(length + 1, maxLength);
    }
    // 标记为已经访问过
    visited[node] = maxLength;
    return maxLength;
  }
};