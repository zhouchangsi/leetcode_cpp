#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == nums[mid ^ 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

TEST(leetcode540, solution) {
  Solution s;
  vector<int> nums;

  nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
  ASSERT_EQ(s.singleNonDuplicate(nums), 2);

  nums = {3, 3, 7, 7, 10, 11, 11};
  ASSERT_EQ(s.singleNonDuplicate(nums), 10);
}