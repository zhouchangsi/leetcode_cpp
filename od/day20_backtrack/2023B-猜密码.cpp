/**
 * https://og7kl7g6h8.feishu.cn/docx/NOBYdTomVosS2KxgSRPceIQgnNd
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  string line = "2,3,4";
  getline(cin, line);
  auto nums = vector<int>();
  stringstream ss(line);
  string num;
  while (getline(ss, num, ',')) {
    nums.push_back(stoi(num));
  }
  int min_len = 2;
  cin >> min_len;

  const int n = nums.size();
  vector<vector<int>> res;
  vector<int> path;
  function<void(int)> backtrack = [&](int start) {
    if (path.size() >= min_len) {
      res.push_back(path);
    }
    if (path.size() == n) {
      return;
    }
    for (int i = start; i < n; i++) {
      path.push_back(nums[i]);
      backtrack(i + 1);
      path.pop_back();
    }
  };
  backtrack(0);
  for (auto &v : res) {
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
      if (i != v.size() - 1) {
        cout << ",";
      }
    }
    cout << "\n";
  }

  return 0;
}