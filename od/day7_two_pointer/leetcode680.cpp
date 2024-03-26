// https://leetcode.com/problems/valid-palindrome-ii/
// https://r07na4yqwor.feishu.cn/docx/XoOfd8yZ3o6pSuxS2dTck2lgnjf
#include <bits/stdc++.h>
using namespace std;

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