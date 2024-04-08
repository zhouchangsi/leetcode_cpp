// https://leetcode-cn.com/problems/3sum-closest/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (abs(sum - target) < abs(ans - target)) ans = sum;
        if (sum < target)
          l++;
        else
          r--;
      }
    }
    return ans;
  }
};