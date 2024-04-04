#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
  vector<vector<int>> res;

  for (int i = 1; i < n; i++) {
    // (i + j)*(j - i + 1)/2 = n
    // j * j - i * i + i + j = n * 2
    // j * j + j = n * 2 + i * i - i
    int target = n * 2 + i * i - i;
    // if (n * n > target) continue;
    int j = i + 1;
    while (j < n) {
      if (j * j + j == target) {
        res.push_back({i, j});
        break;
      }
      j++;
    }
  }

  sort(res.begin(), res.end(),
       [](auto a, auto b) { return a[1] - a[0] < b[1] - b[0]; });

  cout << n << '=' << n << '\n';
  for (auto v : res) {
    cout << n << '=' << v[0];
    for (int i = v[0] + 1; i <= v[1]; i++) {
      cout << '+' << i;
    }
    cout << '\n';
  }
  cout << "Result:" << res.size() + 1 << '\n';
}

int main() {
  //   solve(9);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  solve(n);
  return 0;
}