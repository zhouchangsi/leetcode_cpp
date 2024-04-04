/**
 * https://og7kl7g6h8.feishu.cn/docx/ZLfNdmszho3j44x8Z4FcKyubnxe
 */

#include <iostream>
#include <vector>
using namespace std;

int DIRECTIONS[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;
vector<string> grid;
vector<vector<int>> visited;
int ans = 0;

void dfs(int x, int y, int &current_value) {
  visited[x][y] = 1;
  current_value += grid[x][y] - '0';

  for (auto dir : DIRECTIONS) {
    int nxt_x = x + dir[0];
    int nxt_y = y + dir[1];

    if (nxt_x >= 0 && nxt_x < n && nxt_y >= 0 && nxt_y < m &&
        grid[nxt_x][nxt_y] != '0' && visited[nxt_x][nxt_y] == 0) {
      dfs(nxt_x, nxt_y, current_value);
    }
  }
}

int main() {
  string line;
  while (getline(cin, line) && !line.empty()) {
    grid.push_back(line);
  }

  n = grid.size();
  m = grid[0].size();
  visited.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '0' && visited[i][j] == 0) {
        int current_value = 0;
        dfs(i, j, current_value);
        ans = max(ans, current_value);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
