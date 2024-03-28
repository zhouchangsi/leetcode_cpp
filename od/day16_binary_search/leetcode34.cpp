/**
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * https://r07na4yqwor.feishu.cn/docx/BsQ6dey7AohOGGxDOWScmKTdnhc
*/
#include "../leetcode/leetcode.h"

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int first = -1, last = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        first = mid;
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        last = mid;
        left = mid + 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return {first, last};
  }
};