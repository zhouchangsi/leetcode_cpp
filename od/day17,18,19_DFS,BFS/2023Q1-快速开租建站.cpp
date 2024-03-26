/**
 * https://og7kl7g6h8.feishu.cn/docx/QpfMdpJn2oDJskxdQLkcHpMonAd
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> connection(n);
  vector<int> in_degree(n, 0);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    connection[x].push_back(y);
    in_degree[y]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }

  int level = 0;
  while (!q.empty()) {
    int q_size = q.size();
    level++;
    for (int i = 0; i < q_size; i++) {
      int cur = q.front();
      q.pop();
      for (int next : connection[cur]) {
        in_degree[next]--;
        if (in_degree[next] == 0) {
          q.push(next);
        }
      }
    }
  }

  cout << level << endl;

  return 0;
}
