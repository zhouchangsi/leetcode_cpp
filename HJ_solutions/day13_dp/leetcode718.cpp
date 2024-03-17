/**
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
 * https://r07na4yqwor.feishu.cn/docx/PbJsdeHEjoM3mkxwZm1cslrVnxb
 */
#include "../leetcode/leetcode.h"

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        int max_len = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len;
    }
};