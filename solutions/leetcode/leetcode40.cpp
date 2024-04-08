/**
 * https://leetcode-cn.com/problems/combination-sum-ii/
 * https://r07na4yqwor.feishu.cn/docx/EjqHdur6joFLwsxMHHlccKZtnWd
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    vector<int> path;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, path, res);
    return res;
  }

  void dfs(vector<int>& candidates,
           int target,
           int start,
           vector<int>& path,
           vector<vector<int>>& res)
  {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    if (start == candidates.size())
      return;

    if (target < candidates[start])
      return;

    for (int i = start; i < candidates.size(); ++i) {
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      path.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i + 1, path, res);
      path.pop_back();
    }
  }
};
