/**
 * https://og7kl7g6h8.feishu.cn/docx/Y55Wdg27voWjgNxTFfqci2Sunzg
*/
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> connection;
  string line;
  getline(cin, line);
  stringstream iss(line);
  int val;
  vector<int> firstRow;
  while (iss >> val) {
    firstRow.push_back(val);
  }
  connection.push_back(firstRow);

  int n = firstRow.size();
  for (int i = 1; i < n; i++) {
    getline(cin, line);
    stringstream iss(line);
    vector<int> row;
    while (iss >> val) {
      row.push_back(val);
    }
    connection.push_back(row);
  }

  int ans = 0;
  vector<int> visited(n, 0);

  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      queue<int> q;
      q.push(i);
      visited[i] = 1;

      while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y = 0; y < n; y++) {
          if (x != y && visited[y] == 0 && connection[x][y] == 1) {
            q.push(y);
            visited[y] = 1;
          }
        }
      }
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
