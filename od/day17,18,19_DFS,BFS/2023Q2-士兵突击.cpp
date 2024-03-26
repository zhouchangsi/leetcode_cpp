/**
 * https://og7kl7g6h8.feishu.cn/docx/EEzsdMClwoT7j7xOH9rcUhgLnyV
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  auto grid = vector<vector<char>>(n, vector<char>(m));
  function<bool(int, int)> is_valid_pos = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'X';
  };
  auto time = vector<vector<int>>(n, vector<int>(m, 0));
  queue<tuple<int, int, int, int>> q;
  auto dirs = vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int ex, ey;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < m; j++) {
      grid[i][j] = line[j];
      // 初始化队列q，其中储存四个信息：给士兵S的四周设定
      // 点的x坐标，点的y坐标，到当前位置所需要的步数step，当前前进方向的索引d
      if (grid[i][j] == 'S') {
        for (int d = 0; d < 4; d++) {
          int dx = dirs[d].first, dy = dirs[d].second;
          if (is_valid_pos(i + dx, j + dy)) {
            q.push({i + dx, j + dy, 1, d});
          }
        }
      }
      if (grid[i][j] == 'E') {
        ex = i, ey = j;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y, cur_time, cur_d] = q.front();
    q.pop();
    for (int next_d = 0; next_d < 4; next_d++) {
      int nx = x + dirs[next_d].first, ny = y + dirs[next_d].second;
      if (!is_valid_pos(nx, ny)) continue;
      int next_time = cur_time + next_d == cur_d ? 0 : 1;
      if (next_time <= time[nx][ny]) {
        time[nx][ny] = next_time;
        q.push({nx, ny, cur_time + next_time, next_d});
      }
    }
  }

  cout << time[ex][ey] << endl;
}
