// https://og7kl7g6h8.feishu.cn/docx/HPd9d5pdUoH7t5xvdDMcIVUZnof
#include <bits/stdc++.h>
using namespace std;

void hash_set(vector<int> nums) {
  set<int> nums_set;
  for (auto n : nums) {
    nums_set.insert(n);
  }
  for (auto n : nums_set) {
    cout << n << '\n';
  }
}

int main() {
  int tmp;
  cin >> tmp;
  vector<int> nums;
  int n;
  while (cin >> n) {
    nums.emplace_back(n);
  }

  hash_set(nums);

  return 0;
}