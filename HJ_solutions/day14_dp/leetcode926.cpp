/**
 * https://leetcode.cn/problems/flip-string-to-monotone-increasing/submissions/511667079/
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        auto dp = vector<vector<int>>(n, vector<int>(2));        
        // 0表示不变，1表示变成1
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '0' ? 1 : 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                // 0 -> 0
                dp[i][0] = dp[i - 1][0];
                // 1 -> 0
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            } else {
                // 0 -> 1
                dp[i][0] = dp[i - 1][0] + 1;
                // 1 -> 1
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};