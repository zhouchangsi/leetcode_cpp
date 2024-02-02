#include "./leetcode/env.h"

// leetcode5: 最长回文子串
// https://leetcode-cn.com/problems/longest-palindromic-substring/
// 思路：动态规划
// dp[i][j] 表示 s[i...j] 是否是回文串
// dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
// 边界条件：dp[i][i] = true
//          dp[i][i + 1] = s[i] == s[i + 1]
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int max_len = 1, start = 0;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        max_len = 2;
        start = i;
      }
    }
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          max_len = len;
          start = i;
        }
      }
    }
    return s.substr(start, max_len);
  }
};