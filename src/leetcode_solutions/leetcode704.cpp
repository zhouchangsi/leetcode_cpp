#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  static int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = (left + right) >> 1;
    while (left < right) {
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > target)
        right = mid - 1;
      if (nums[mid] < target)
        left = mid + 1;
      mid = (left + right) >> 1;
    }
    if (nums[left] == target)
      return left;
    else
      return -1;
  }
};

TEST(leetcode704, solution) {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  Solution solution;
  int res = solution.search(nums, 9);
  EXPECT_EQ(res, 4);
}
