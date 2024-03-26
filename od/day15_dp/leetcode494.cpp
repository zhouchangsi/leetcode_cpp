/**
 * https://leetcode.cn/problems/target-sum/description/
 * https://r07na4yqwor.feishu.cn/docx/KEbNdiODUovK2xxgjhJcQ6AqnGb
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // 每个数字都有两种状态：被进行“+”， 或者被进行“-”
        // 因此可以将数组分成 A 和 B 两个部分
        // A 部分的数字全部进行“+”操作
        // B 部分的数字全部进行“-”操作

        // 设数组的和为 sum ，A 部分的和为 sumA ，B 部分的和为 sumB

        // sumA + sumB = sum (1)
        // 同时有： sumA - sumB = target (2)
        // 将(1)式与(2)式相加，可以得到： 2sumA = sum + target (3)
        // 即 sumA = (sum + target) / 2 
        // 所以，原问题转换为：
        // 有一些物品，第 i 个物品的重量为 nums[i] ， 背包的容量为 sumA ，问：有多少种方式将背包【恰好填满】


        // 先去计算总和
        int sum = 0;

        for (int num : nums) {

            sum += num;

        }

        // 再去计算背包容量
        // sumA - sumB = target
        // sumA + sumB = sum
        // sumA = (target + sum) / 2
        int bagSize = (target + sum) / 2;

        // 题目有可能出现 target 是一个很小的负数
        // 比如 nums = [ 100 ] ，target = -200
        // 这个时候 bagSize 就是负数了，需要调整为正数
        if (bagSize < 0) bagSize = -bagSize;

        // System.out.println(bagSize);

        // 如果发现 target + sum 为奇数，则无解
        // 比如 nums = [ 1 ] ，target = 2
        // target + sum = 2 + 1 = 3 ，此时无解
        // 因为 bagSize 必然是整数，即 (target + sum) / 2 必然是整数
        // 那么只有 target + sum 为偶数才能得到整数
        if ((target + sum) % 2 == 1) return 0;

        // 在前 i 个数字中，凑出和为 j 的组合有多少种方法
        // dp[0][0] 表示在前 0 个数字中，凑出和为 0 的组合，有多少种方法
        vector<vector<int>> dp(nums.size() + 1, vector<int>(bagSize + 1));
        // 初始化
        for (int i = 0; i <= nums.size(); i++) {
            // 在前 i 个数字中，凑出和为 0 的组合有多少种方法
            // 答案是 1 种方法
            // 即每次不选择第 i 个元素就行
            dp[i][0] = 1;
            // System.out.print(dp[i][0] + " ");
        }
        // System.out.println("");

        // 01 背包问题开始填充二维数组
        for (int i = 1; i <= nums.size(); i++) {

            for (int j = 0; j <= bagSize; j++) {

                // 注意到 i 是从下标 1 开始访问的
                // 1、背包容量小于当前元素
                // 背包无法放入 nums[i - 1]
                if( j < nums[i - 1]){

                    dp[i][j] = dp[i - 1][j];

                // 2、背包容量大于等于当前元素
                // 背包可以放入 nums[i - 1]
                }else{

                    // 不选：方案数为 dp[i - 1][j]
                    // 选：方案数为 dp[i - 1][j - nums[i - 1]]
                    // 两者之和
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }

                // System.out.print(dp[i][j] + " ");
         
            }
            // System.out.println("");
        }

        // 返回结果
        return dp[nums.size()][bagSize];

    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int n = nums.size(), neg = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(neg + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 0; j <= neg; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j - num];
                }
            }
        }
        return dp[n][neg];
    }
};
