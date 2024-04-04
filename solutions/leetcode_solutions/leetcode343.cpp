#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int integerBreak(int n) {
    auto dp = vector<int>(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      int max_num = 0;
      for (int j = 1; j < i; j++) {
        max_num = max(max_num, max(j * (i - j), j * dp[i - j]));
      }
      dp[i] = max_num;
    }
    return dp[n];
  }
};