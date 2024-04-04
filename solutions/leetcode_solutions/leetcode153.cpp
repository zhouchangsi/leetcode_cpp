#include <gtest/gtest.h>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[left] < nums[right]) {
        return nums[left];
      } else if (nums[left] > nums[right]) {
        if (nums[mid] >= nums[left]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      } else {
        left++;
      }
    }
    return nums[left];
  }
};

TEST(leetcode153, solution) {
  Solution solution;
  vector<int> nums = {3, 4, 5, 1, 2};
  int expected = 1;
  ASSERT_EQ(expected, solution.findMin(nums));
}