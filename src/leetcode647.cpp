#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  int countSubstrings(string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
      int l = i / 2, r = i / 2 + i % 2;
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
        ++ans;
      }
    }
    return ans;
  }
};

TEST(leetcode647, case1) {
  MyQueue s;
  EXPECT_EQ(s.countSubstrings("abc"), 3);
  EXPECT_EQ(s.countSubstrings("aaa"), 6);
}