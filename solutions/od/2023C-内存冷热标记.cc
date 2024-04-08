#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int k) {
  int n = nums.size();
  unordered_map<int, int> count;
  for (auto n : nums) count[n]++;
  int ans = 0;
  vector<int> ids;
  for (auto [id, cnt] : count) {
    if (cnt >= k) {
      ans++;
      ids.emplace_back(id);
    };
  }

  sort(ids.begin(), ids.end(), [&](int a, int b) {
    if (count[a] == count[b]) return a < b;
    return count[a] > count[b];
  });

  cout << ans << '\n';
  for (auto id : ids) {
    cout << id << '\n';
  }
}

int main() {
  int n;
  cin >> n;
  auto nums = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  int k;
  cin >> k;
  solve(nums, k);

  return 0;
}