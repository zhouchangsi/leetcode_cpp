// https://leetcode.com/problems/palindrome-number/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPalindrome(int left) {
    if (left == 0) {
      return true;
    }
    if (left < 0 || left % 10 == 0) {
      return false;
    }
    int right = 0;
    while (left > right) {
      right = right * 10 + left % 10;
      left /= 10;
    }
    return left == right || left == right / 10;
  }
};
