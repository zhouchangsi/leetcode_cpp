#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }

    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (fabs(x0 - xi) < 1e-7) {
        break;
      }
      x0 = xi;
    }
    return int(x0);
  }
};

TEST(leetcode69, solution) {
  Solution s;
  EXPECT_EQ(s.mySqrt(4), 2);
  EXPECT_EQ(s.mySqrt(8), 2);
  EXPECT_EQ(s.mySqrt(9), 3);
  EXPECT_EQ(s.mySqrt(10), 3);
  EXPECT_EQ(s.mySqrt(2147395599), 46339);
}