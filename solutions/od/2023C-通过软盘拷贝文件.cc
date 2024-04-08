#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> files) {
  int block_limit = 1474560 / 512;
  int n = files.size();
  auto dp = vector<int>(block_limit + 1);

  for (int i = 0; i < n; i++) {
    const int block_size = (files[i] - 1) / 512 + 1;  // 向上取整 (a-1)/b + 1
    for (int j = block_limit; j >= block_size; j--) {
      dp[j] = max(dp[j], dp[j - block_size] + files[i]);
    }
  }

  cout << dp[block_limit] << endl;
}

int main() {
  // solve({400000, 200000, 200000, 200000, 400000, 400000});

  int n;
  cin >> n;
  vector<int> files(n);
  for (int i = 0; i < n; i++) {
    cin >> files[i];
  }
  solve(files);
}