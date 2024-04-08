/**
 * https://leetcode.cn/problems/last-stone-weight-ii/description/
 * https://r07na4yqwor.feishu.cn/docx/FW03dy2IwoPyAwx70XocW5xLnxg
*/
#include "../leetcode.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        // 在两块石头碰撞过程中，可以每次把大的石头划分到 A 部分，小的石头划分到 B 部分
        // 因此可以将数组分成 A 和 B 两个部分
        // A 部分的石头可以被部分留下
        // B 部分的石头全部被粉碎

        // 接下来就是需要思考到底哪些石头放入 A 部分，哪些石头放入 B 部分
        // 其中 A 部分的石头重量和是 sumA
        // 其中 B 部分的石头重量和是 sumB
        // 为了使得最后剩下的石头尽可能的小，那么总是会想去构造 { a , b } 这两个石头的差值尽可能的小
        // 于是问题就变成了：从 stones 中选择一些元素，总和不超过 sum / 2 的最大值

        // 先去计算总和
        const int& sum = accumulate(stones.begin(), stones.end(), 0);
        // (4 - 2) - (8 - 7) - 1 - 1 = 0
        // ans = sum - x;
        // 要让 ans 尽可能的小，即 x 尽可能的大
        // 于是问题就变成了：从 stones 中选择一些元素，总和不超过 sum / 2 的最大值
        int target = sum / 2;

        // dp[i][j] 代表考虑前 i 个物品（数值），凑成总和不超过 j 的最大价值
        vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1));

        // 01 背包问题开始填充二维数组
        for( int i = 1 ; i <= stones.size()  ; i++){

            for( int j = 0 ; j <= target ; j++){

                // 注意到 i 是从下标 1 开始访问的
                // 1、背包容量小于当前元素
                // 背包无法放入 stones[i - 1]
                if ( j < stones[i - 1]){

                    dp[i][j] = dp[ i - 1 ][j];

                // 2、背包容量大于等于当前元素
                // 背包可以放入 stones[i - 1]
                }else{

                    // 不选：方案数为 dp[i - 1][j]
                    // 选：方案数为 dp[i - 1][j - stones[i - 1]] + stones[i-1]
                    dp[i][j] = max(dp[i-1][j] , dp[i-1][j - stones[i-1]] + stones[i-1]);
                }
            }
        }
       
        // 这两个部分最大值是 dp[stones.length][target]，剩余的部分就是剩下的石头
        return abs(sum - dp[stones.size()][target] - dp[stones.size()][target]);

    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        int n = stones.size();
        vector<int> dp(target + 1);
        for (int i = 1; i <= n; i++) {
            int cur_stone = stones[i - 1];
            for (int j = target; j >= 0; j--) {
                if (j - cur_stone >= 0) {
                    dp[j] = max(dp[j], dp[j - cur_stone] + cur_stone);
                }
            }
        }
        return abs(sum - dp[target] - dp[target]);
    }
};