/**
 * https://leetcode.cn/problems/missing-number/description/
 */
#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int missingNumber(vector<int> &nums) {
    int temp = 0;
    for (int i = 0; i < nums.size(); i++) {
      temp = temp ^ nums[i] ^ i;
    }
    return temp ^ nums.size();
  }
};

TEST(leetcode268, case1) {
  Solution s;
  EXPECT_EQ(s.missingNumber(vector<int>{3, 0, 1}), 2);
  EXPECT_EQ(s.missingNumber(vector<int>{0, 1}), 2);
  EXPECT_EQ(s.missingNumber(vector<int>{9, 6, 4, 2, 3, 5, 7, 0, 1}), 8);
  EXPECT_EQ(s.missingNumber(vector<int>{0}), 1);
}