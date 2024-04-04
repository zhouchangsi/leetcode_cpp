#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
  }
};

TEST(leetcode342, solution) {
  Solution s;
  EXPECT_EQ(s.isPowerOfFour(16), true);
  EXPECT_EQ(s.isPowerOfFour(5), false);
  EXPECT_EQ(s.isPowerOfFour(1), true);
}