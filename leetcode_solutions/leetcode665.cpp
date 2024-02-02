#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2)
      return true;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1]) {
        ++cnt;
        if (cnt > 1)
          return false;
        if (i == 1 || nums[i] >= nums[i - 2]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
      }
    }
    return true;
  }
};

TEST(leetcode665, solution) {
  Solution s;
  EXPECT_EQ(1, 1);
}