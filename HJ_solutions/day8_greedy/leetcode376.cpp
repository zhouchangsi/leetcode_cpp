#include "leetcode.h"
/**
 * https://r07na4yqwor.feishu.cn/docx/NQx7dYoXGo2i1exqtNScRIvlnNJ
 * https://leetcode.cn/problems/wiggle-subsequence/submissions/499423844/
 */
class Solution
{
public:
  int wiggleMaxLength(vector<int>& nums)
  {
    if (nums.size() < 2) {
      return nums.size();
    }

    // 关键是看方向的变化，如果方向变化了，那么就是一个峰或者谷
    int prev_diff = nums[1] - nums[0];
    int res = prev_diff != 0 ? 2 : 1;
    for (int i = 2; i < nums.size(); i++) {
      int diff = nums[i] - nums[i - 1];
      // 只要方向变化了， 就是一个峰或者谷， 那么就可以加1
      if ((diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0)) {
        res++;
        prev_diff = diff;
      }
    }

    return res;
  }
};