/**
 * https://leetcode.cn/problems/coin-change/
 * https://r07na4yqwor.feishu.cn/docx/Gw10dk3EnoQsu6xAjxHcIGevnyc
*/

#include "../leetcode/leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // 二维数组：状态定义:dp[i][j]表示从前 i 个物品中选择不超过 j 重量的物品的最大价值
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

        dp[0][0] = 0;

        // Tips：前 i 个物品表示的是编号从 [ 0 , i - 1] 这些物品，即最后一个物品编号为 i - 1
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                // 背包容量小于当前物品的容量，即背包容量已经不足以拿第 i 个物品了
                // 第 i 个物品即下标为 i - 1 的那个物品
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                // 背包容量足够拿第 i 个物品，那么可拿也可不拿
                // 1、拿了，那么最大价值是前 i 个物品扣除第 i 个物品的重量的情况下的最大价值，再加上【第 i 个】物品的价值
                // 2、不拿，那么就是从前 i - 1 个物品中选择出的最大价值
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }

        return dp[n][amount] == amount + 1 ? -1 : dp[n][amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};