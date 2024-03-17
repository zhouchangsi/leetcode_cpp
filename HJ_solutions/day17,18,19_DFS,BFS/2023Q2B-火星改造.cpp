/**
 * https://og7kl7g6h8.feishu.cn/docx/HMGgdM8bzouRQsxNMQicf1fKncb
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  auto grid = vector<vector<string>>(n, vector<string>(m, ""));
  auto visited = vector<vector<bool>>(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  int num_no = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == "YES") {
        q.push({i, j});
        visited[i][j] = true;
      } else if (grid[i][j] == "NO") {
        num_no++;
      }
    }
  }
  auto dirs = vector<pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
  int count = 0;
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    level++;
    for (int i = 0; i < size; i++) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        if (grid[nx][ny] == "NO") {
          num_no--;
          if (num_no == 0) {
            cout << level - 1 << endl;
            return 0;
          }
        }
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}