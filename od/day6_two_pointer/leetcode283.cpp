//  https://leetcode-cn.com/problems/move-zeroes/
// https://ahym1n4sq5.feishu.cn/docx/BgbudqqEEoEHjRxjiV8c1LHwnBc
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    for (int r = 0; r < n; r++) {
      if (nums[r] == 0) continue;
      swap(nums[l], nums[r]);
      l++;
    }
  }
};