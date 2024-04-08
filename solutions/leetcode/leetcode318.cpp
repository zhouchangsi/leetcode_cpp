#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> mask(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
      for (char c : words[i]) {
        mask[i] |= 1 << (c - 'a');
      }
    }

    int maxProd = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if ((mask[i] & mask[j]) == 0) {
          maxProd = max(maxProd, int(words[i].size() * words[j].size()));
        }
      }
    }

    return maxProd;
  }
};

TEST(leetcode318, solution) {
  Solution s;
  vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
  EXPECT_EQ(s.maxProduct(words), 16);
}

TEST(leetcode318, case2) {
  Solution s;
  vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
  EXPECT_EQ(s.maxProduct(words), 4);
}

TEST(leetcode318, case3) {
  Solution s;
  vector<string> words = {"a", "aa", "aaa", "aaaa"};
  EXPECT_EQ(s.maxProduct(words), 0);
}