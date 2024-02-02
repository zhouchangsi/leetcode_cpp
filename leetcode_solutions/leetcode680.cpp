#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool is_palindrome(string& s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
  bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return is_palindrome(s, left + 1, right) ||
               is_palindrome(s, left, right - 1);
      }
      left++;
      right--;
    }
    return true;
  }

};

TEST(leetcode680, solution) {
  EXPECT_TRUE(Solution().validPalindrome("aba"));
  EXPECT_TRUE(Solution().validPalindrome("abca"));
  EXPECT_FALSE(Solution().validPalindrome("abc"));
}