#include "./leetcode/env.h"

/**
 * dp[i] = i个不同的数组成的二叉搜索数的个数
 * 假设 i = 5
 * 当根节点等于 1 时 ，其余数字都比1大，只能在右边 dp[5] += dp[4]
 * 当根节点等于 2 时，左边有一个1比2小，右边有三个比2大的数字 dp[5] += dp[1] *
 * dp[3] 当根节点等于 3 时，左边有两个数比3小，右边有两个数比3大的数字 dp[5] +=
 * dp[2] * dp[2]
 * ...
 * 知道根节点等于5，左边有4个数字比5小，只能放在5的左边,dp[5] += dp[4]
 */
class Solution
{
public:
  int numTrees(int n)
  {
    vector<int> dp(n + 1, 0);
    // dp[i] 表示以 i 为根节点的二叉搜索树的个数
    dp[0] = 1;
    dp[1] = 1;
    // 以 i 为根节点，左子树的节点个数为 j，右子树的节点个数为 i - j - 1
    // dp[i] += dp[j] * dp[i - j - 1]
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j)
        dp[i] += dp[j] * dp[i - j - 1];
    }
    return dp[n];
  }
};