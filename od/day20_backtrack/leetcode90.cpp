/**
 * https://leetcode-cn.com/problems/subsets-ii/
 * https://r07na4yqwor.feishu.cn/docx/NE4hdFzBaoQJoAxuWIIcriY3n8g
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) return res;
    sort(nums.begin(), nums.end());
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
      res.push_back(path);
      for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        dfs(i + 1);
        path.pop_back();
      }
    };
    dfs(0);
    return res;
  }

  // void dfs(vector<int>& nums, int start, vector<int>& path,
  //          vector<vector<int>>& res) {
  //   res.push_back(path);

  //   for (int i = start; i < nums.size(); ++i) {
  //     if (i > start && nums[i] == nums[i - 1]) continue;
  //     path.push_back(nums[i]);
  //     dfs(nums, i + 1, path, res);
  //     path.pop_back();
  //   }
  // }
};
