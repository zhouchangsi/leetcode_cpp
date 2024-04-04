/**
 * https://leetcode.cn/problems/n-th-tribonacci-number/
 * https://r07na4yqwor.feishu.cn/docx/KypfdpPRIoTjOmxWkLHcFa9vnpd
 */
class Solution {
public:
    int tribonacci(int n) {
        int dp[3] = {0, 1, 1};
        if(n < 3) {
            return dp[n];
        }
        int ans = 0;
        for(int i = 3; i <=n; i++) {
            ans = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = ans;
        }
        return ans;
    }
};