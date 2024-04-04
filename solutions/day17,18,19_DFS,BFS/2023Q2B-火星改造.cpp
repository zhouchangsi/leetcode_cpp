/**
 * https://og7kl7g6h8.feishu.cn/docx/HMGgdM8bzouRQsxNMQicf1fKncb
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<string>> grid;
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    string token;
    vector<string> row;
    while (ss >> token) {
      row.push_back(token);
    }
    grid.push_back(row);
  }

  //   vector<vector<string>> grid = {
  //       {"YES", "YES", "NO"},  //
  //       {"NO", "NO", "NO"},    //
  //       {"NA", "NO", "YES"}    //
  //   };

  int n = grid.size(), m = grid[0].size();
  int num_no = 0;
  auto visited = vector<vector<bool>>(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == "YES") {
        q.push({i, j});
        visited[i][j] = true;
      } else if (grid[i][j] == "NO") {
        num_no++;
      }
    }
  }
  int level = 0;
  auto dirs = vector<pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
  while (!q.empty()) {
    int size = q.size();
    level++;
    for (int i = 0; i < size; i++) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m ||  // pos
            visited[nx][ny] || grid[nx][ny] == "NA"    //
        ) {
          continue;
        }
        if (grid[nx][ny] == "NO") {
          num_no--;
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
  }
  cout << (num_no > 0 ? -1 : level - 1) << '\n';
}