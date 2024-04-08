/**
 * https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/510260602/
 * https://r07na4yqwor.feishu.cn/docx/SSkgdsJs6osuKRxvLzCcODYZnAh
*/
#include "../leetcode.h"

class Solution
{
public:
  int minSubArrayLen(int target, vector<int>& nums)
  {
    int n = nums.size();
    int l = 0, r = 0;

    int sum = 0;
    int min_len = INT_MAX;
    while (r < n) {
      sum += nums[r];
      if (sum >= target) {
        while (l <= r && sum >= target) {
          min_len = min(min_len, r - l + 1);
          sum -= nums[l++];
        }
      }       ++r;
    }
    return min_len == INT_MAX? 0: min_len; 
  }
};