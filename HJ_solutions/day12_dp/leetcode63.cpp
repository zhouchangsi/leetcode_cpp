/**
 * https://leetcode.cn/problems/unique-paths-ii/
 * https://r07na4yqwor.feishu.cn/docx/M6VodwxeiolTbmxH78cc49PXnvf
 */
#include "../leetcode/leetcode.h"
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            // 一旦出现了障碍，那么后面所有的位置都是到达不了的，都是默认的 0
            if (obstacleGrid[i][0] == 1)
                break;
            // 仅此一条，别无分路
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            // 一旦出现了障碍，那么后面所有的位置都是到达不了的，都是默认的 0
            if (obstacleGrid[0][j] == 1)
                break;
            // 仅此一条，别无分路
            dp[0][j] = 1;
        }
        // 接下来从第 1 行到第 m - 1 行
        // 从第 1 列到 n - 1 列
        // 填充二维数组 dp 里面的值
        // dp[i][j] 表示从第 0 行第 0 列到达第 i 行第 j 列时不同路径的数量
        for (int i = 1; i < m; i++)
        {

            for (int j = 1; j < n; j++)
            {
                // 由于每次只能向下或者向右移动一步

                // 如果此时出现了障碍，那么由于无法到达这个位置，因此不用处理
                if (obstacleGrid[i][j] == 1)
                    continue;

                // 位置 (i,j) 的不同路径的数量是由
                // 1、上边位置 dp[ i - 1 ][j] 的不同路径的数量
                // 2、左边位置 dp[i][ j - 1 ] 的不同路径的数量
                // 两者之和获取到的
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};