#include "./leetcode/env.h"

class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    int n = nums.size();
    vector<int> res(n, 1);
    int left = 1;
    // 算某个数字左边的乘积
    // 1   2   3   4
    // 1   1   2   6
    for (int i = 0; i < n; ++i) {
      res[i] *= left;
      left *= nums[i];
    }
    // 算某个数字右边的乘积, 并乘到左边的乘积上
    // 1   1   2   6
    // 24  12  8   6
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
      res[i] *= right;
      right *= nums[i];
    }
    return res;
  }
};