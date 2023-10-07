#include "common_headers.h"

using namespace std;

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
  EXPECT_TRUE(Solution().judgeSquareSum(5));
  EXPECT_FALSE(Solution().judgeSquareSum(3));
  EXPECT_FALSE(Solution().judgeSquareSum(2147482647));
}