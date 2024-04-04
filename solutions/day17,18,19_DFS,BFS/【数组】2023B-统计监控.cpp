/**
 * https://og7kl7g6h8.feishu.cn/docx/IComdGbRro179rxj3XRcuKoenXt
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  auto grid = vector<vector<int>>(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  auto dirs = vector<pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        count++;
      } else {
        for (auto &[dx, dy] : dirs) {
          int x = i + dx, y = j + dy;
          if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
            count++;
            break;
          }
        }
      }
    }
  }

  cout << count << '\n';

  return 0;
}