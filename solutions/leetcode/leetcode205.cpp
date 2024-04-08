// https://leetcode.com/problems/isomorphic-strings/
// https://ahym1n4sq5.feishu.cn/docx/YKNldtOvGo4IL1xbkRTcBnOmn5e
#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
      char x = s[i], y = t[i];
      if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
        return false;
      }
      s2t[x] = y;
      t2s[y] = x;
    }
    return true;
  }
};

TEST(leetcode205, solution) {
  Solution s;
  EXPECT_EQ(s.isIsomorphic("egg", "add"), true);
  EXPECT_EQ(s.isIsomorphic("foo", "bar"), false);
  EXPECT_EQ(s.isIsomorphic("paper", "title"), true);
}