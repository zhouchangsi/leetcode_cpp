/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 * https://r07na4yqwor.feishu.cn/docx/RDwadmv7EoK3oDx3qdpcTuchnRg
*/

#include "../leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0; // 假设默认持有0元股票
        for(int i=1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
        }

        return max(dp[n-1][1], dp[n-1][2]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 先获取数组的长度
         int length = prices.size();

        // 设置一个三维数组 dp
        // dp[i][k][b]
        // i 表示天数，dp[i] 表示第 i 天的最大利润
        // k 表示最多交易次数，每次交易包含买入和卖出，这里只在买入的时候将 k - 1
        // 注意：【 k 表示最多交易次数，而不是实际交易次数，比如最多交易两次可能实际只交易一次】
        // b 表示当前是否持有股票，取值为 0 和 1
        // 其中 0 表示当前持有 0 份股票，即【不持有】股票
        // 而 1 表示当前持有 1 份股票，即【持有】股票
        
        // 在本题中，k 的值为正无穷，i 的取值范围为数组 prices 的长度，从 0 开始
        auto dp = vector < vector < int>> ( length ,vector<int> ( 2));

        // dp[0][0][0] 表示在第 0 天结束时，即收盘后，手上持有 0 份股票，且此时最多进行了 0 次交易的情况下可以获得的最大收益
        // 此时，就是什么都没做，利润为 0
        dp[0][0] = 0;

        // dp[0][k][0] 表示在第 0 天结束时，即收盘后，手上持有 0 份股票，且此时最多进行了 k 次交易的情况下可以获得的最大收益
        // 此时，就是什么都没做，利润为 0
        dp[0][0] = 0;

        // dp[0][k][1] 表示在第 0 天结束时，即收盘后，手上持有 1 份股票，且此时最多进行了 k 次交易的情况下可以获得的最大收益
        // 手上持有了 1 份股票，那肯定是执行了买入操作，然后又还没有卖出，那么钱都投入了股票中，利润就是负的，即为 -prices[0]
        dp[0][1] = -prices[0];

        // 动态规划：自底向上，即从前向后遍历，实现一个萝卜一个坑
        for (int i = 1; i < length; i++) {
            
            // 对于每个坑来说，都有两种状态
            // 今天也就是第 i 天

            // 1、今天【不持有】股票
            // 第 i - 1 天【持有】股票，第 i 天卖出
            // 昨天【持有】股票，今天卖出
            // vs
            // 第 i - 1 天【不持有】股票，第 i 天不操作
            // 昨天【不持有】股票，今天不操作
            dp[i][0] = max( dp[i - 1][0] , dp[i - 1][1] + prices[i] ) ;

            // 2、今天【持有】股票
            // 第 i - 1 天【持有】股票，第 i 天不操作
            // 昨天【持有】股票，今天不操作
            // vs
            // 第 i - 1 天【不持有】股票，第 i 天买入
            // 昨天【不持有】股票，今天买入
            dp[i][1] = max( dp[i - 1][1] ,   (i >= 2 ? dp[i - 2][0] : 0 ) - prices[i] ) ;

        }

        // for 循环结束后，dp 数组填充完毕
        // dp[length - 1][k][0]
        // 表示第 length - 1 天结束时，即收盘后，手上持有 0 份股票，且此时最多进行了 k 次交易的情况下可以获得的最大收益
        return dp[length - 1][0];
    }
};