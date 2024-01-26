#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      swap(s[l], s[r]);
      l++;
      r--;
    }
  }
};

TEST(leetcode344, solution) {
  Solution solution;
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  solution.reverseString(s);
  EXPECT_EQ(s, vector<char>({'o', 'l', 'l', 'e', 'h'}));
}
