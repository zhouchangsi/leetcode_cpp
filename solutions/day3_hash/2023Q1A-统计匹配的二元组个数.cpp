// https://og7kl7g6h8.feishu.cn/docx/DQqWdgqIhoXKikxDYFHcGhnwnah
#include <bits/stdc++.h>
using namespace std;

void hash_map(vector<int> a, vector<int> b) {
  unordered_map<int, int> count_a, count_b;
  for (auto n : a) count_a[n]++;
  for (auto n : b) count_b[n]++;

  int sum = 0;
  for (auto [num, count] : count_a) {
    if (count_b.count(num)) {
      sum += count_a[num] * count_b[num];
    }
  }
  cout << sum << '\n';
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> a(m), b(n);
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  hash_map(a, b);
  return 0;
}