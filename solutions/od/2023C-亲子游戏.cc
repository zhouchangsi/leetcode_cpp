#include <bits/stdc++.h>
using namespace std;

auto dirs = vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(vector<vector<int>> candy) {
  int n = candy.size(), m = candy[0].size();
  int sx, sy, ex, ey;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (candy[i][j] == -3) sx = i, sy = j;
      if (candy[i][j] == -2) ex = i, ey = j;
    }
  }

  // max_candy
  auto mc = vector<vector<int>>(n, vector<int>(m, -1));
  auto step = vector<vector<int>>(n, vector<int>(m, INT_MAX));
  mc[sx][sy] = step[sx][sy] = candy[sx][sy] = candy[ex][ey] = 0;

  queue<pair<int, int>> q;
  q.push({sx, sy});

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (candy[nx][ny] == -1) continue;
        int new_candy = mc[x][y] + candy[nx][ny], new_step = step[x][y] + 1;
        if (new_step > step[nx][ny]) continue;
        if (new_step < step[nx][ny]) {
          step[nx][ny] = new_step;
          q.push({nx, ny});
        }

        if (new_candy > mc[nx][ny]) {
          mc[nx][ny] = new_candy;
        }
      }
    }
  }

  cout << mc[ex][ey] << endl;
}

int main() {
  // solve({
  //     {3, 2, 1, -3},  //
  //     {1, -1, 1, 1},  //
  //     {1, 1, -1, 2},  //
  //     {-2, 1, 2, 3}   //
  // });
  // int n;
  // cin >> n;
  // auto candy = vector<vector<int>>(n, vector<int>(n));
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cin >> candy[i][j];
  //   }
  // }

  // solve(candy);
  return 0;
}