#include <bits/stdc++.h>
using namespace std;

void solve(string a, string b) {
  int n = a.size();
  int m = b.size();
  auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));
  for (int i = 0; i < n + 1; i++) dp[i][0] = i;
  for (int i = 0; i < n + 1; i++) dp[0][i] = i;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  cout << dp[n][m] << endl;
}

int main() {
  // solve("ABC", "ABC");
  // solve("ABCABBA", "CBABAC");
  string a, b;
  cin >> a >> b;
  solve(a, b);
}