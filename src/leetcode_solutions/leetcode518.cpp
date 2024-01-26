#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int change(int amount, vector<int>& coins)
  {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (auto& coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i - coin];
      }
    }

    return dp[amount];
  }
};

TEST(leetcode518, solution)
{
  Solution s;
  vector<int> coins = { 1, 2, 5 };
  EXPECT_EQ(4, s.change(5, coins));
}