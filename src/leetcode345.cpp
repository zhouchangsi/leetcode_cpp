#include "common_headers.h"

using namespace std;

class Solution {
 public:
  bool is_vowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    }
    return false;
  }
  string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right && !is_vowel(s[left])) {
        left++;
      }
      while (left < right && !is_vowel(s[right])) {
        right--;
      }
      if (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
      }
    }
    return s;
  }
};

TEST(leetcode345, solution) {
  EXPECT_EQ(Solution().reverseVowels("hello"), "holle");
  EXPECT_EQ(Solution().reverseVowels("leetcode"), "leotcede");
}