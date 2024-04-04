#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> ids, vector<vector<int>> grid) {
  const int& n = grid.size();
  auto connected = unordered_set<int>();

  function<void(int)> dfs = [&](int id) {
    if (connected.count(id)) {
      return;
    }
    connected.insert(id);

    for (int next = 0; next < n; next++) {
      int cur = grid[id][next];
      if (cur == 0) continue;
      dfs(next);
    }
  };

  for (auto id : ids) {
    for (int next = 0; next < n; next++) {
      int cur = grid[id][next];
      if (cur == 1) {
        dfs(next);
      }
    }
  }

  cout << connected.size() - ids.size() << endl;
}

int main() {
  //   solve({1, 2}, {{1, 1, 0, 1, 0},
  //                  {1, 1, 0, 0, 0},
  //                  {0, 0, 1, 0, 1},
  //                  {1, 0, 0, 1, 0},
  //                  {0, 0, 1, 0, 1}});

  int n;
  cin >> n >> ws;

  vector<int> ids;
  string line;
  getline(cin, line);
  stringstream ss(line);
  while (getline(ss, line, ',')) {
    ids.push_back(stoi(line));
  }

  auto grid = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    for (int j = 0; j < n; j++) {
      getline(ss, line, ',');
      grid[i][j] = stoi(line);
    }
  }
  solve(ids, grid);
}