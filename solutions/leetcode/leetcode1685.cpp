/**
 * https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
 * https://r07na4yqwor.feishu.cn/docx/XK6NdE2fSooE7cxdbY3ckbA9neB
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int targetSum = accumulate(nums.begin(), nums.end(), 0) - x;
    if (targetSum == 0) {
      return nums.size();
    }

    int windowSum = 0;
    int windowLenMax = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
      // A1
      windowSum += nums[right];
      // A2
      while (left <= right && windowSum > targetSum) {
        windowSum -= nums[left];
        left++;
      }
      // A3
      if (windowSum == targetSum) {
        windowLenMax = max(right - left + 1, windowLenMax);
      }
    }

    return windowLenMax == 0 ? -1 : nums.size() - windowLenMax;
  }
};
