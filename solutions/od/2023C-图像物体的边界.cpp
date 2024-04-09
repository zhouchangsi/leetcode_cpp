#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},  //
                               {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void dfs_boundary(vector<vector<int>> &grid, int i, int j) {
  int m = grid.size(), n = grid[0].size();
  grid[i][j] = 1;

  for (auto [dx, dy] : dirs) {
    int x = i + dx, y = j + dy;
    if (x < 0 || y >= m || x < 0 || y >= n ||  //
        grid[x][y] == 1 || grid[x][y] == 5     //
    ) {
      continue;
    }
    dfs_boundary(grid, x, y);
  }
}

void count_boundary(vector<vector<int>> grid) {
  int m = grid.size(), n = grid[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] != 5) continue;
      for (auto [dx, dy] : dirs) {
        int x = i + dx, y = j + dy;
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 5) continue;
        grid[x][y] = 3;
      }
    }
  }

  int count{};
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 3) {
        count++;
        dfs_boundary(grid, i, j);
      }
    }
  }

  cout << count << '\n';
}

int main() {
  count_boundary({{1, 1, 1, 1, 1, 1},
                  {1, 5, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1, 1},
                  {1, 1, 1, 1, 1, 5}});

  // int m{}, n{};
  // cin >> m >> n;
  // vector<vector<int>> grid(n, vector<int>(m));
  // for (int i = 0; i < m; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cin >> grid[i][j];
  //   }
  // }
  // cout << Solution().count_boundary(grid) << endl;

  return 0;
}
