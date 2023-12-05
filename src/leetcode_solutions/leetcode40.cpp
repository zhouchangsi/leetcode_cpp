#include "common_headers.h"

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

TEST(leetcode40, solution)
{
  Solution solution;
  vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
  int target = 8;
  vector<vector<int>> res = solution.combinationSum2(candidates, target);
  vector<vector<int>> expect = { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } };
  multiset<vector<int>> s(res.begin(), res.end());
  multiset<vector<int>> e(expect.begin(), expect.end());
  EXPECT_EQ(s, e);
}