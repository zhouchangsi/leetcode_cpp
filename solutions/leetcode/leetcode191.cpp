// https://leetcode.com/problems/number-of-1-bits/
class Solution {
 public:
  int hammingWeight(int n) {
    int c = 0;
    while (n) {
      n &= n - 1;
      c++;
    }
    return c;
  }
};