/**
 * https://leetcode.cn/problems/permutations/
 * https://r07na4yqwor.feishu.cn/docx/RkVxdL0DvoWOWwxtq41cogVAnub
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums);
    return pre_order_notes;
  }

  vector<vector<int>> pre_order_notes;
  vector<int> path;
  void dfs(vector<int>& nums) {
    if (path.size() == nums.size()) {
      pre_order_notes.push_back(path);
      return;
    }
    for (auto n : nums) {
      if (find(path.begin(), path.end(), n) != path.end()) continue;
      path.push_back(n);
      dfs(nums);
      path.pop_back();
    }
  }
};
