/**
 * https://leetcode.cn/problems/partition-equal-subset-sum/
 * https://r07na4yqwor.feishu.cn/docx/FiIkdMurPogrqxxXAHMc2yxVn1d
 */

#include "../leetcode/leetcode.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return false;
        int sum = 0, max_num = 0;
        for (auto num : nums)
        {
            sum += num;
            max_num = max(max_num, num);
        }
        // 如果nums的总和是奇数，那怎么分都不会出现子集的和是总和的一半，因为总和的一半是小数。
        if (sum & 1)
            return false;

        int target = sum / 2;
        if (max_num > target)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; ++i)
            dp[i][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            // 给定一个容量pack_cap = sum/2的背包，求其最多能装多重的石头，我们将nums[i]视为第i个石头的重量。
            // 如果装下sum/2重量的石头，说明剩余的石头和也为sum/2，则符合题意。
            for (int j = 1; j <= target; ++j)
            {
                if (j >= num)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][target];
    }
};

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 使用 sum 来保存数组中全部元素的和
        int sum = 0;

        // 遍历 nums 数组
        for (int i = 0; i < nums.size(); i++)
        {
            // 把 nums 数组上的所有元素值累加到 sum 上
            sum += nums[i];
        }

        // 如果发现 sum 为奇数，那么必然无法拆分为两个相等的整数
        if (sum % 2 == 1)
        {
            // 所以无法将这个数组分割成两个子集，返回false
            return false;
        }

        // 获取数组的长度
        int n = nums.size();

        // 获取数组中全部元素之后的一半
        // 接下来需要在数组 nums 中寻找一些数字去拼凑为 target
        // 如果能找到一些数字之和为 target，那么剩下的数字之和也是 target
        int target = sum / 2;

        // dp[i][j] 表示 nums 的前 i 个元素能否可以组成和为 j 的结果
        // dp[0][0] 表示 nums 的前 0 个元素能否可以组成和为 0 的结果
        // dp[2][6] 表示 nums 的前 2 个元素能否可以组成和为 6 的结果
        // dp[n - 1][target ] 表示 nums 的前 n - 1 个元素能否可以组成和为 target 的结果
        // i 的值从 0 到 n - 1
        // j 的值从 0 到 target
        auto dp = vector<vector<bool>>(n, vector<bool>(target + 1));

        // 先初始化  dp[0][nums[0]]
        // 如果 nums 的第 0 个元素 nums[0] 小于 target
        if (nums[0] <= target)
        {
            // 那么 nums 的前 0 个元素能否可以组成和为 nums[0] 的结果是 true
            // 因为 nums 的前 0 个元素就是 nums[0]
            dp[0][nums[0]] = true;
        }

        // 接下来开始往 dp 数组中填充结果
        // i 的值从 1 到 n - 1
        for (int i = 1; i < n; i++)
        {
            // j 的值从 0 到 target
            for (int j = 0; j <= target; j++)
            {
                // dp[i][j] 表示 nums 的前 i 个元素能否可以组成和为 j 的结果
                // dp[i - 1][j] 表示 nums 的前 i - 1 个元素能否可以组成和为 j 的结果
                // 对于 dp[i][j] 来说，如果 dp[i - 1][j] 为 true，那么 dp[i][j] 必然也为 true
                // 所以，先初始化 dp[i][j] 的值为 dp[i - 1][j] 的值
                // 再通过后面的代码修改 dp[i][j] 中还为 false 的值
                dp[i][j] = dp[i - 1][j];

                // 如果此时 nums[i] 恰巧为 j
                // 那么对于 dp[i][j] 来说，nums 的前 i 个元素可以组成和为 j 的结果
                if (nums[i] == j)
                {
                    // 所以 dp[i][j] 为 true
                    dp[i][j] = true;
                    // 同时继续
                    continue;
                }

                // 如果发现 nums[i] 小于 j
                if (nums[i] < j)
                {
                    // dp[i][j] 表示 nums 的前 i 个元素能否可以组成和为 j 的结果
                    // dp[i - 1][j] 表示 nums 的前 i - 1 个元素能否可以组成和为 j 的结果
                    // dp[i - 1][j - nums[i]] 表示 nums 的前 i - 1 个元素能否可以组成和为 j - nums[i] 的结果
                    // 那么 dp[i][j] 的结果要为 true
                    // 1、nums 的前 i - 1 个元素可以组成和为 j
                    // 2、nums 的前 i - 1 个元素可以组成和为 j - nums[i]
                    // 对于 1 来说，不用使用 nums[i] 就组成了 j
                    // 对于 2 来说，前 i - 1 个元素可以组成和为 j - nums[i]，那么加上此时的值 nums[i]，也组成了 j
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        // dp[n - 1][target ] 表示 nums 的前 n - 1 个元素能否可以组成和为 target 的结果
        // 返回这个结果
        return dp[n - 1][target];
    }
};