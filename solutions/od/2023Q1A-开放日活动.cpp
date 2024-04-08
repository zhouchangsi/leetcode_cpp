/**
 * https://og7kl7g6h8.feishu.cn/docx/Q9ILdheU6ompXdxmneucN3cLnog
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int get_sum_with_max_cap(int max_capacity, const vector<int>& nums) {
  int sum = 0;
  for (int num : nums) {
    sum += min(num, max_capacity);
  }
  return sum;
}

int main() {
  int SUM, n;
  cin >> SUM >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  if (accumulate(nums.begin(), nums.end(), 0) < SUM) {
    cout << "[]" << endl;
    return -1;
  }
  int left = 1;
  int right = *max_element(nums.begin(), nums.end()) + 1;

  while (left < right) {
    int mid = (left + right) / 2;
    if (get_sum_with_max_cap(mid, nums) > SUM) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  int max_capacity = left - 1;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = (nums[i] < max_capacity) ? 0 : (nums[i] - max_capacity);
  }

  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i != n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
  return 0;
}
