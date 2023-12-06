#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int n1 = text1.size(), n2 = text2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; ++i) {
      char c1 = text1[i - 1];
      for (int j = 1; j <= n2; ++j) {
        char c2 = text2[j - 1];
        if (c1 == c2) {
          dp[i][j] = dp[i - 1][j - 1] + 1; // match
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // not match
        }
      }
    }

    return dp[n1][n2];
  }
};

TEST(leetcode1143, solution)
{
  Solution s;
  EXPECT_EQ(s.longestCommonSubsequence("abcde", "ace"), 3);
  EXPECT_EQ(s.longestCommonSubsequence("abc", "abc"), 3);
  EXPECT_EQ(s.longestCommonSubsequence("abc", "def"), 0);
}