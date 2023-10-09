#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool hasAlternatingBits(int n) {
    long tmp = n ^ (n >> 1);
    return (tmp & (tmp + 1)) == 0;
  }
};

TEST(leetcode639, solution) {
  Solution s;
  EXPECT_EQ(s.hasAlternatingBits(5), true);
  EXPECT_EQ(s.hasAlternatingBits(7), false);
  EXPECT_EQ(s.hasAlternatingBits(11), false);
  EXPECT_EQ(s.hasAlternatingBits(1431655765), true);
}