/**
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * https://r07na4yqwor.feishu.cn/docx/BsQ6dey7AohOGGxDOWScmKTdnhc
 */
#include "../leetcode.h"

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

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    // 第一个>=target的数
    auto start = lower_bound(nums.begin(), nums.end(), target);
    

    // auto end = upper_bound(nums.begin(), nums.end(), target);
    if (start == nums.end() || *start != target) {
      return {-1, -1};
    }

    // (nums[last] <= x) means
    // (nums[first] > x) means
    // (nums[first] >= x + 1)
    // last = find the first element that is >= target + 1 and -1
    auto end = lower_bound(nums.begin(), nums.end(), target + 1) - 1;
    int first = start - nums.begin();
    int last = end - nums.begin();
    return {first, last};
  }
};