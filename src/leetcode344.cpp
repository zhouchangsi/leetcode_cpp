#include "common_headers.h"

using namespace std;

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

TEST(leetcode344, case1) {
  Solution solution;
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  solution.reverseString(s);
  EXPECT_EQ(s, vector<char>({'o', 'l', 'l', 'e', 'h'}));
}

TEST(leetcode344, case2) {
  Solution solution;
  vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
  solution.reverseString(s);
  EXPECT_EQ(s, vector<char>({'h', 'a', 'n', 'n', 'a', 'H'}));
}
