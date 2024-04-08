/**
 * https://leetcode.cn/problems/coin-change-ii/description/
 * https://r07na4yqwor.feishu.cn/docx/DtX4dSBZjoV1i0xS2AxcAgGdnve
*/

#include "../leetcode.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        // 经典的完全背包问题

        // 二维数组：状态定义:dp[i][j]表示从数组 coins 中前 i 个硬币中选择得到价值为 j 的硬币组合数
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1 , 0));

        // 只有当不选取任何硬币时，金额之和才为 0，此时只有 1 种硬币组合
        dp[0][0] = 1;

        // Tips：前 i 个物品表示的是编号从 [ 0 , i - 1] 这些物品，即最后一个物品编号为 i - 1
        // coins 数组的大小就是硬币的个数
        for( int i = 1 ; i <= n ; i++){
            // 遍历背包容量
            for( int j = 0 ; j <= amount ; j++){

                // 背包容量小于当前硬币的值，即背包容量已经不足以拿第 i 个硬币了
                // 第 i 个硬币即下标为 i - 1 的那个硬币
                if( j < coins[i - 1]){

                    // 硬币组合数就是去考虑当前背包容量情况下，从前 i - 1 个物品中选择出的硬币组合数
                    dp[i][j] = dp[i - 1][j];

                // 背包容量足够拿第 i 个物品，那么可拿也可不拿
                // 1、拿了，那么硬币组合数是前 i 个硬币扣除第 i 个硬币的情况下的硬币组合数
                // 2、不拿，那么就是从前 i - 1 个硬币中选择出的硬币组合数
                }else{

                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }

            }

        }

        return dp[n][amount];

    }
};

class Solution
{
public:
  int change(int amount, vector<int>& coins)
  {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (auto& coin : coins) {
      for (int i = coin; i <= amount; i++) {
        dp[i] += dp[i - coin];
      }
    }

    return dp[amount];
  }
};