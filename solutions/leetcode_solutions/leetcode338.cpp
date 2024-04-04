#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i & (i - 1)] + 1;
    }
    return dp;
  }
};

TEST(leetcode338, solution) {
  Solution s;
  EXPECT_EQ(s.countBits(2), vector<int>({0, 1, 1}));
  EXPECT_EQ(s.countBits(5), vector<int>({0, 1, 1, 2, 1, 2}));
}