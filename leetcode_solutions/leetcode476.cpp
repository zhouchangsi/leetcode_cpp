#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int findComplement(int num) {
    unsigned int mask = 0;
    while (mask < num) {
      mask = (mask << 1) + 1;
    }
    return num ^ mask;
  }
};

TEST(leetcode476, solution) {
  Solution s;
  EXPECT_EQ(s.findComplement(5), 2);
  EXPECT_EQ(s.findComplement(1), 0);
  EXPECT_EQ(s.findComplement(2147483647), 0);
}