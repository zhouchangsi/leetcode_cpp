#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    unsigned int left = 0, right = sqrt(c);
    while (left <= right) {
      unsigned int sum = left * left + right * right;
      if (sum == c) {
        return true;
      } else if (sum < c) {
        left++;
      } else {
        right--;
      }
    }
    return false;
  }
};

TEST(leetcode633, solution) {
  Solution s;
  EXPECT_TRUE(s.judgeSquareSum(5));
  EXPECT_FALSE(s.judgeSquareSum(3));
  EXPECT_FALSE(s.judgeSquareSum(2147482647));
}