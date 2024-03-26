// https://leetcode-cn.com/problems/3sum/
// https://ahym1n4sq5.feishu.cn/docx/WBOtd914RouWijxjOZ5cBVQ2ngv

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) l++;
          while (l < r && nums[r] == nums[r - 1]) r--;
          l++, r--;
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};