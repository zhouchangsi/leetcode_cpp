#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  int getSum(int a, int b) {
    while (b != 0) {
      unsigned int carry = (unsigned int)(a & b) << 1;
      a = a ^ b;
      b = carry;
    }
    return a;
  }
};

TEST(leetcode371, case1) {
  MyQueue s;
  EXPECT_EQ(s.getSum(1, 2), 3);
  EXPECT_EQ(s.getSum(2, 3), 5);
  EXPECT_EQ(s.getSum(3, 4), 7);
  EXPECT_EQ(s.getSum(4, 5), 9);
  EXPECT_EQ(s.getSum(5, 6), 11);
}