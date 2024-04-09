#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    unordered_map<int, vector<int>> g;
    for (auto& e : dislikes) {
      int a = e[0] - 1, b = e[1] - 1;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    vector<int> group(n, 0);  // 0: unvisited, 1: group1, 2: group2

    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (group[i] != 0) continue;
      q.push(i);
      group[i] = 1;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int& other : g[cur]) {

          if (group[other] > 0 && group[other] == group[cur]) {
            return false;
          }

          if (group[other] == 0) {
            group[other] = group[cur] == 1 ? 2 : 1;
            q.emplace(other);
          }
        }
      }
    }

    return true;
  }
};