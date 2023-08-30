#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  bool isPalindrome(int x) {
    if (x == 0) {
      return true;
    }
    if (x < 0 || x % 10 == 0) {
      return false;
    }
    int right = 0;
    while (x > right) {
      right = right * 10 + x % 10;
      x /= 10;
    }
    return x == right || x == right / 10;
  }
};

TEST(leetcode9, case1) {
  MyQueue s;
  EXPECT_EQ(s.isPalindrome(121), true);
  EXPECT_EQ(s.isPalindrome(-121), false);
  EXPECT_EQ(s.isPalindrome(10), false);
}