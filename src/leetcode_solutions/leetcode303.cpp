#include "common_headers.h"

using namespace std;

class NumArray
{
public:
  NumArray(vector<int>& nums)
  {
    int n = nums.size();
    dp.resize(n, vector<int>(n, 0));
    for (int left = 0; left < n; ++left) {
      for (int right = left; right < n; ++right) {
        if (left == right) {
          dp[left][right] = nums[left];
        } else {
          dp[left][right] = dp[left][right - 1] + nums[right];
        }
      }
    }
  }

  int sumRange(int left, int right) { return dp[left][right]; }

private:
  vector<vector<int>> dp;
};

TEST(leetcode303, solution)
{
  vector<int> nums;
  NumArray s(nums);

  nums = { 2, 3, 2 };
  ASSERT_EQ(s.sumRange(0, 2), 3);

  nums = { 1, 2, 3, 1 };
  ASSERT_EQ(s.sumRange(0, 3), 4);

  nums = { 0 };
  ASSERT_EQ(s.sumRange(0, 0), 0);

  nums = { 1 };
  ASSERT_EQ(s.sumRange(0, 0), 1);

  nums = { 1, 2 };
  ASSERT_EQ(s.sumRange(0, 1), 3);

  nums = { 2, 1 };
  ASSERT_EQ(s.sumRange(0, 1), 3);
}