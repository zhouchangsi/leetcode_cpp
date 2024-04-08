/**
 * https://og7kl7g6h8.feishu.cn/docx/NrkadphAXojW25x2oq7cZWHmnLe
 */
#include <bits/stdc++.h>
using namespace std;

void solution(string line) {
  vector<int> nums;
  istringstream iss(line);
  int num;
  while (iss >> num) nums.push_back(num);

  sort(nums.begin(), nums.end());

  int l = 0, r = nums.size() - 1;
  tuple<int, int, int> res = {nums[l], nums[r], abs(nums[l] + nums[r])};

  int min_abs_sum = INT_MAX;
  while (l < r) {
    int sum = nums[l] + nums[r];
    if (abs(sum) < min_abs_sum) {
      res = {nums[l], nums[r], abs(sum)};
      min_abs_sum = abs(sum);
    }
    if (sum == 0) break;
    sum < 0 ? l++ : r--;
  }

  auto [a, b, c] = res;
  cout << a << " " << b << " " << c;
};

int main() {
  // solution("-1 -3 7 5 11 15");

  string line;
  getline(cin, line);
  solution(line);
  return 0;
}