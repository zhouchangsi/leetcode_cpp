#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    // 统计各字符数量
    unordered_map<char, int> counter;
    for (char c : s)
      counter[c]++;
    // 统计构造回文串的最大长度
    int res = 0, odd = 0;
    for (auto kv : counter) {
      // 将当前字符出现次数向下取偶数，并计入 res
      int count = kv.second;
      res += count - (count & 1);
      // 若当前字符出现次数为奇数，则将 odd 置 1
      if (count & 1)
        odd = 1;
    }
    return res + odd;
  }
};

TEST(leetcode409, case1) {
  Solution solution;
  ASSERT_EQ(solution.longestPalindrome("abccccdd"), 7);
  ASSERT_EQ(solution.longestPalindrome("a"), 1);
  ASSERT_EQ(solution.longestPalindrome("aaaaaccc"), 7);
}