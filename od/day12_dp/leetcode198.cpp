/**
 * https://leetcode.cn/problems/house-robber/description/
 * https://r07na4yqwor.feishu.cn/docx/KLAKdHtCpoAJClxpTVWc0w04ndc
*/

#include "../leetcode/leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.begin(), nums.end());
        int n = nums.size();
        if (2 < n) {
            dp[2] += dp[0];
        }
        for (int i = 3; i < n; i++) {
            dp[i] += max(dp[i - 2], dp[i - 3]);
        }
        int ans = INT_MIN;
        for(auto const &s:dp) {
            ans = max(ans, s);
        }
        return ans;
    }
};