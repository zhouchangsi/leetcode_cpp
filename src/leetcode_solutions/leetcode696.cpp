#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> counts;
    int ptr = 0, n = s.size();
    while (ptr < n) {
      char c = s[ptr];
      int count = 0;
      while (ptr < n && s[ptr] == c) {
        ++ptr;
        ++count;
      }
      counts.push_back(count);
    }
    int ans = 0;
    for (int i = 1; i < counts.size(); ++i) {
      ans += min(counts[i], counts[i - 1]);
    }
    return ans;
  }
};

TEST(leetcode696, solution) {
  Solution s;
  EXPECT_EQ(s.countBinarySubstrings("00110011"), 6);
  EXPECT_EQ(s.countBinarySubstrings("10101"), 4);
}