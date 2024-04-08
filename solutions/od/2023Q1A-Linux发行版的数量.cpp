/**
 * https://og7kl7g6h8.feishu.cn/docx/QJrYdFGcro67xfxhuy6cpanMnog
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> isConnected(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> isConnected[i][j];
    }
  }

  int ans = 0;
  vector<int> visited(n, 0);

  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      queue<int> q;
      q.push(i);
      visited[i] = 1;
      int curNum = 0;

      while (!q.empty()) {
        int x = q.front();
        q.pop();
        curNum++;

        for (int y = 0; y < n; y++) {
          if (x != y && visited[y] == 0 && isConnected[x][y] == 1) {
            q.push(y);
            visited[y] = 1;
          }
        }
      }

      ans = max(ans, curNum);
    }
  }

  cout << ans << endl;
  return 0;
}
