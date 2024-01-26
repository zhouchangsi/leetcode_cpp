#include "common_headers.h"

using namespace std;

class Solution
{
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    vector<vector<int>> res;
    if (nums.empty())
      return res;

    sort(nums.begin(), nums.end());
    vector<int> path;
    dfs(nums, 0, path, res);
    return res;
  }

  void dfs(vector<int>& nums,
           int start,
           vector<int>& path,
           vector<vector<int>>& res)
  {
    res.push_back(path);

    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      dfs(nums, i + 1, path, res);
      path.pop_back();
    }
  }
};

TEST(leetcode90, solution)
{
  Solution solution;
  vector<int> nums = { 1, 2, 2 };
  vector<vector<int>> res = solution.subsetsWithDup(nums);
  vector<vector<int>> expect = { { 2 },    { 1 },    { 1, 2, 2 },
                                 { 2, 2 }, { 1, 2 }, {} };
  multiset<vector<int>> s(res.begin(), res.end());
  multiset<vector<int>> e(expect.begin(), expect.end());
  EXPECT_EQ(s, e);
}