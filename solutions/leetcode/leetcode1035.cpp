/**
 * https://leetcode.cn/problems/uncrossed-lines/description/
 */
#include "../leetcode.h"

/**
 * 这是一道「最长公共子序列（LCS）」的轻度变形题。
 */
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int a = nums1[i - 1], b = nums2[j - 1];
                int &cur = dp[i][j];
                int &left = dp[i][j - 1];
                int &up = dp[i - 1][j];
                cur = a == b ? dp[i - 1][j - 1] + 1 : max(left, up);
            }
        }
        return dp[n][m];
    }
};