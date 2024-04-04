/**
 * https://leetcode.cn/problems/minimum-path-sum/description/
 * https://r07na4yqwor.feishu.cn/docx/D1xRdsv94oeVObxVLrocdNPrnqf
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    } 
};