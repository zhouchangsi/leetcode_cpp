/**
 * https://leetcode.cn/problems/missing-number/description/
 */
#include <vector>
#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int temp = 0;
    for (int i = 0; i < nums.size(); i++) {
      temp = temp ^ nums[i] ^ i;
    }
    return temp ^ nums.size();
  }
};

TEST(leetcode268, case1) {
  Solution s;
  vector<int> nums = {3, 0, 1};
  EXPECT_EQ(s.missingNumber(nums), 2);
}