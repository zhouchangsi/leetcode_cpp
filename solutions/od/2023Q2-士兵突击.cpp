/**
 * https://og7kl7g6h8.feishu.cn/docx/EEzsdMClwoT7j7xOH9rcUhgLnyV
 */
#include <bits/stdc++.h>
using namespace std;

auto dirs = vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct Info {
  int x;
  int y;
  int time;
  int d;
};

void bfs(vector<vector<char>> grid) {
  int n = grid.size();
  int m = grid[0].size();
  auto is_valid_pos = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 'X';
  };
  auto time = vector<vector<int>>(n, vector<int>(m, INT_MAX));
  queue<Info> q;

  int ex, ey;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 初始化队列q，其中储存四个信息：给士兵S的四周设定
      // 点的x坐标，点的y坐标，到当前位置所需要的步数step，当前前进方向的索引d
      if (grid[i][j] == 'S') {
        time[i][j] = 0;
        for (int d = 0; d < 4; d++) {
          int nx = i + dirs[d].first, ny = j + dirs[d].second;
          if (is_valid_pos(nx, ny)) continue;
          q.push({nx, ny, 1, d});
          time[nx][ny] = 1;
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
      int next_time = cur_time + 1 + (next_d == cur_d ? 0 : 1);
      if (next_time <= time[nx][ny]) {
        time[nx][ny] = next_time;
        q.push({nx, ny, next_time, next_d});
      }
    }
  }

  if (time[ex][ey] == INT_MAX)
    cout << -1 << '\n';
  else
    cout << time[ex][ey] << '\n';
}

int main() {
  bfs({{'S', 'B', 'B', 'B', 'B', 'B'},
       {'B', 'X', 'X', 'X', 'X', 'B'},
       {'B', 'B', 'X', 'B', 'B', 'B'},
       {'X', 'B', 'B', 'X', 'X', 'B'},
       {'B', 'X', 'B', 'B', 'X', 'B'},
       {'B', 'B', 'X', 'B', 'E', 'B'}});
  // int n, m;
  // cin >> n >> m >> ws;
  // auto grid = vector<vector<char>>(n, vector<char>(m));
}
