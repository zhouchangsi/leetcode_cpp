#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int rob(vector<int>& nums)
  {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    int n = nums.size();
    vector<int> dp(n, 0);
    // 偷第一家，不偷最后一家
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n - 1; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    int ans = dp[n - 2];

    // 不偷第一家，偷最后一家
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    ans = max(ans, dp[n - 1]);

    return ans;
  }
};

TEST(leetcode213, solution)
{
  Solution s;
  vector<int> nums;

  nums = { 2, 3, 2 };
  ASSERT_EQ(s.rob(nums), 3);

  nums = { 1, 2, 3, 1 };
  ASSERT_EQ(s.rob(nums), 4);

  nums = { 0 };
  ASSERT_EQ(s.rob(nums), 0);

  nums = { 1 };
  ASSERT_EQ(s.rob(nums), 1);

  nums = { 1, 2 };
  ASSERT_EQ(s.rob(nums), 2);

  nums = { 2, 1 };
  ASSERT_EQ(s.rob(nums), 2);

  nums = { 2, 1, 1, 2 };
  ASSERT_EQ(s.rob(nums), 3);

  nums = { 2, 1, 1, 2, 1 };
  ASSERT_EQ(s.rob(nums), 4);

  nums = { 2, 1, 1, 2, 1, 1 };
  ASSERT_EQ(s.rob(nums), 4);

  nums = { 2, 1, 1, 2, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 5);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 5);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 6);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 6);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 7);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 7);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 8);

  nums = { 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
  ASSERT_EQ(s.rob(nums), 8);
}