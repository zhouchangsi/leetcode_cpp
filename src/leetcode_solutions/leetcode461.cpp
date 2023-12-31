#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    while (z) {
      z &= (z - 1);
      count++;
    }
    return count;
  }
};

TEST(leetcode461, solution) {
  Solution s;
  EXPECT_EQ(s.hammingDistance(1, 4), 2);
}

TEST(leetcode461, case2) {
  Solution s;
  EXPECT_EQ(s.hammingDistance(3, 1), 1);
}