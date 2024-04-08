#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    const int& n = nums.size();
    vector<int> max_left(n), min_right(n);
    int max_num = nums[0], min_num = nums[n - 1];
    int l = 0, r = -1;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < max_num) {
        r = i;
      } else {
        max_num = nums[i];
      }

      if (nums[n - 1 - i] > min_num) {
        l = n - 1 - i;
      } else {
        min_num = nums[n - 1 - i];
      }
    }

    return r - l + 1;
  }
};