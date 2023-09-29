#include "common_headers.h"

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      } else {
        ++j;
      }
    }
    return i == s.size();
  }
};

TEST(leetcode392, solution) {
  Solution s;
  EXPECT_TRUE(s.isSubsequence("abc", "ahbgdc"));
  EXPECT_FALSE(s.isSubsequence("axc", "ahbgdc"));
}