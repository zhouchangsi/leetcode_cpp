/**
 * https://leetcode.cn/problems/combination-sum/description/
 * https://r07na4yqwor.feishu.cn/docx/IoQfdhXfho9KNhxs8kActy33nOg
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    function<void(int, int)> dfs = [&](int start, int target) {
      if (start == candidates.size()) return;
      if (target == 0) {
        res.push_back(path);
        return;
      }
      dfs(start + 1, target);
      if (target - candidates[start] >= 0) {
        path.push_back(candidates[start]);
        dfs(start, target - candidates[start]);
        path.pop_back();
      }
    };
    dfs(0, target);
    return res;
  }
};