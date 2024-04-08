/**
 * https://og7kl7g6h8.feishu.cn/docx/FrEfdLy2VoOqstxEOLJc7UFMnxc
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  auto distance = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> distance[i][j];
    }
  }
  int min_cost = INT_MAX;
  int path_sum = 0;
  auto visited = vector<bool>(n, false);
  visited[0] = true;
  function<void(int)> dfs = [&](int start) {
    if (path_sum >= min_cost) return;
    bool all_visited =
        all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    if (all_visited) {
      min_cost = min(min_cost, path_sum + distance[start][0]);
      return;
    }
    for (int i = 1; i < n; i++) {
      if (visited[i]) continue;
      path_sum += distance[start][i];
      visited[i] = true;
      dfs(i);
      path_sum -= distance[start][i];
      visited[i] = false;
    }
  };
  dfs(0);
  cout << min_cost << endl;
}