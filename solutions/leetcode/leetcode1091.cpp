#include "common_headers.h"

using namespace std;
class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0)
      return -1;
    if (grid[0][0] == 1)
      return -1;
    if (n == 1)
      return 1;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      int step = visited[x][y]; // step 表示到达(x,y)的最短路径长度
      for (int i = 0; i < 8; ++i) { // 8个方向
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) // 越界
          continue;
        if (grid[nx][ny] == 1) // 障碍物
          continue;
        if (visited[nx][ny] != 0) // 已经访问过
          continue;
        if (nx == n - 1 && ny == n - 1) // 到达终点
          return step + 1;
        visited[nx][ny] = step + 1;
        q.push({nx, ny});
      }
    }

    return -1;
  }
};
TEST(leetcode1091, solution) {}