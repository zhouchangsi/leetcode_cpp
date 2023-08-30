#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if(i == 0) {
          dp[i][j] = j;
          continue;
        }

        if(j == 0) {
          dp[i][j] = i;
          continue;
        }

        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          int insert = dp[i][j - 1] + 1;
          int del = dp[i - 1][j] + 1;
          int replace = dp[i - 1][j - 1] + 1;
          dp[i][j] = min(insert, min(del, replace));
        }
      }
    }
    return dp[n][m];
  }
};

TEST(leetcode72, case1) {
  MyQueue s;
  EXPECT_EQ(s.minDistance("horse", "ros"), 3);
  EXPECT_EQ(s.minDistance("intention", "execution"), 5);
}