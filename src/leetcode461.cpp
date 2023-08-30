#include "common_headers.h"

using namespace std;

class MyQueue {
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

TEST(leetcode461, case1) {
  MyQueue s;
  EXPECT_EQ(s.hammingDistance(1, 4), 2);
}

TEST(leetcode461, case2) {
  MyQueue s;
  EXPECT_EQ(s.hammingDistance(3, 1), 1);
}