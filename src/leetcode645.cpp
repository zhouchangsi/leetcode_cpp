#include "common_headers.h"

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int dup = -1;
    for (int i = 0; i < n; i++) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] < 0) {
        dup = abs(nums[i]);
      } else {
        nums[idx] *= -1;
      }
    }
    int missing = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        missing = i + 1;
      }
    }
    return {dup, missing};
  }
};

TEST(leetcode645, case1) {
  Solution s;
  vector<int> nums = {1, 2, 2, 4};
  vector<int> expected = {2, 3};
  EXPECT_EQ(s.findErrorNums(nums), expected);
}