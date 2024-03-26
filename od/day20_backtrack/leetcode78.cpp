/**
 * https://leetcode-cn.com/problems/subsets/
 * https://r07na4yqwor.feishu.cn/docx/I0gYdFj6kodD0LxDVvwcNz1Dndc
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(int)> backtrack = [&](int start) {
      res.push_back(path);
      for (int i = start; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(i + 1);
        path.pop_back();
      }
    };
    backtrack(0);
    return res;
  }
};