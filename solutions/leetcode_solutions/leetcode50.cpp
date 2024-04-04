#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double helper(double x, long long n) {
    if (n == 1) return x;
    double half = helper(x, n / 2);
    if (n % 2 == 0) return half * half;
    return half * half * x;
  }
  double myPow(double x, long long n) {
    if (n == 0 || x == 1) return 1;
    if (n < 0) {
      return 1 / helper(x, abs(n));
    }
    return helper(x, n);
  }
};