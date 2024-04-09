/**
 * https://leetcode-cn.com/problems/koko-eating-bananas/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 0, r = pow(10, 9);
    // 找到第一个大于等于ans的数
    while (l <= r) {  // [l, r]
      int m = l + (r - l) / 2;
      if (check(piles, h, m))
        r = m - 1; // [l, m - 1]
      else
        l = m + 1; // [m + 1, r]
    }
    return l;
  }
  bool check(vector<int>& piles, int h, int k) {
    if (k == 0) return false;
    long long time = 0;
    for (auto p : piles) time += (p - 1) / k + 1;
    return time <= h;
  }
};