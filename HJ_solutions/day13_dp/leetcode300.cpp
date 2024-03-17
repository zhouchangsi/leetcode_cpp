/**
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 * https://r07na4yqwor.feishu.cn/docx/RkH9d0RykoYM9rxoUe4cw79enpg
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        auto dp = vector<int>(n, 1);
        int max_len = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_len = max(max_len, dp[i]);
                }
            }
        }
        return max_len;
    }
};