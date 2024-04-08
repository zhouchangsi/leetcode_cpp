#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    dp[0] = s[0] == '0' ? 0 : 1;

    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        if (s[i - 1] == '0' ||  //...00
            s[i - 1] > '2')     //...30
        {
          return 0;
        } else {
          dp[i] = i == 1 ? 1           // 10, 20
                         : dp[i - 2];  //
        }

      } else {
        if (s[i - 1] == '0'                     // .+0[1-9]$
            || s[i - 1] > '2'                   // .+[3-9][1-9]$
            || (s[i - 1] == '2' && s[i] > '6')  // .+2[7-9]$
        )
          dp[i] = dp[i - 1];
        else
          dp[i] = i == 1 ? dp[i - 1] + 1  // 1x, 2x
                         : dp[i - 1] + dp[i - 2];
      }
    }

    return dp[n - 1];
  }
};