class Solution {
 public:
  bool hasAlternatingBits(int n) {
    // n = 5 = 101
    long tmp = n ^ (n >> 1); // 101 ^ 010 = 111
    // long > int, 所以加一不会回落
    return (tmp & (tmp + 1)) == 0; // 0111 & 1000 = 0000
  }
};