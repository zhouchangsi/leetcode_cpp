#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    const int n = nums.size();
    int max_cj = nums[0], min_cj = nums[0];
    int res = nums[0];
    for (int i = 1; i < n; i++) {
      const int cur = nums[i];
      const int _max_cj = max({max_cj * cur, min_cj * cur, cur});
      const int _min_cj = min({max_cj * cur, min_cj * cur, cur});
      max_cj = _max_cj;
      min_cj = _min_cj;
      res = max(res, max_cj);
    }
    return res;
  }
};