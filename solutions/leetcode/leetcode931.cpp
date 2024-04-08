#include "../leetcode.h"

/**
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/
 * https://r07na4yqwor.feishu.cn/docx/PGPSdp9U1okI0VxpkvDcDRwxnDd
 */
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(n + 2, 0));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int mn = dp[i - 1][j];
                if (j > 0)
                {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1)
                {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
