/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
 * https://r07na4yqwor.feishu.cn/docx/SQIvd09qPouWBjxatnPccDrrn9g
 */
#include "../leetcode.h"
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int size = prices.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int j = 1; j <= k; j++)
        {
            //  dp[0][j][0] 表示在第 0 天结束时，即收盘后，手上持有 0
            //  份股票，且此时最多进行了 j 次交易的情况下可以获得的最大收益
            dp[0][j][0] = 0;

            // dp[0][j][1] 表示在第 0 天结束时，即收盘后，手上持有 1
            // 份股票，且此时最多进行了 j 次交易的情况下可以获得的最大收益
            // 手上持有了 1
            // 份股票，那肯定是执行了买入操作，然后又还没有卖出，那么钱都投入了股票中，利润就是负的，即为
            // -prices[0]
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < size; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                // 对于每个坑来说，都有两种状态
                // 今天也就是第 i 天

                // 1、今天【不持有】股票
                // 第 i - 1 天【持有】股票，第 i 天卖出
                // 昨天【持有】股票，今天卖出
                // vs
                // 第 i - 1 天【不持有】股票，第 i 天不操作
                // 昨天【不持有】股票，今天不操作
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // 2、今天【持有】股票
                // 第 i - 1 天【持有】股票，第 i 天不操作
                // 昨天【持有】股票，今天不操作
                // vs
                // 第 i - 1 天【不持有】股票，第 i 天买入
                // 昨天【不持有】股票，今天买入
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[size - 1][k][0];
    }
};