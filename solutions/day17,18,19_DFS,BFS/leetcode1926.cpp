/**
 * https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int, int>> q;
    int n = maze.size(), m = maze[0].size();
    int ox = entrance[0], oy = entrance[1];
    function<bool(int, int)> is_exist = [&](int x, int y) {
      return !(x == ox && y == oy) &&
             (x == 0 || x == n - 1 || y == 0 || y == m - 1);
    };
    q.push({ox, oy});

    auto dirs = vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int steps = 0;

    while (!q.empty()) {
      int sz = q.size();
      while (sz--) {
        auto [x, y] = q.front();
        q.pop();

        // is it a valid exit?
        if (is_exist(x, y)) {
          return steps;
        }

        // add all valid neighbors
        for (auto [dx, dy] : dirs) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (maze[nx][ny] == '+') continue;
          maze[nx][ny] = '+';
          q.push({nx, ny});
        }
      }
      steps++;
    }
    return -1;
  }
};