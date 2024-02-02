#include "common_headers.h"

using namespace std;

class Solution
{
public:
  // dp
  int numberOfArithmeticSlices(vector<int>& nums)
  {
    int n = nums.size();
    if (n < 3)
      return 0;

    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = 0;
    int ans = 0;
    for (int i = 2; i < n; ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        dp[i] = dp[i - 1] + 1;
        ans += dp[i];
      }
    }

    return ans;
  }
  // recursive
  // int numberOfArithmeticSlices(vector<int>& nums)
  // {
  //   int n = nums.size();
  //   if (n < 3)
  //     return 0;
  //
  //   int ans = 0;
  //   for (int i = 0; i < n - 2; ++i) {
  //     ans += numberOfArithmeticSlices(nums, i);
  //   }
  //
  //   return ans;
  // }
  //
  // int numberOfArithmeticSlices(vector<int>& nums, int start)
  // {
  //   int n = nums.size();
  //   if (start >= n - 2)
  //     return 0;
  //
  //   int ans = 0;
  //   int diff = nums[start + 1] - nums[start];
  //   for (int i = start + 2; i < n; ++i) {
  //     if (nums[i] - nums[i - 1] == diff) {
  //       ans += 1 + numberOfArithmeticSlices(nums, i);
  //     } else {
  //       break;
  //     }
  //   }
  //
  //   return ans;
  // }
};

TEST(leetcode413, solution) {}