/**
 * https://leetcode.cn/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
 * https://r07na4yqwor.feishu.cn/docx/XvXodAQNboB6GLx3MhtcK3QanOf
 */

#include "../leetcode/leetcode.h"

class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int min_sub = nums[k - 1] - nums[0];
    for (int r = k, l = 1; r < nums.size(); r++, l++) {
      min_sub = min(min_sub, nums[r] - nums[l]);
    }
    return min_sub;
  }
};