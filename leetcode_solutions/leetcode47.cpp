#include "common_headers.h"

using namespace std;

class Solution
{
public:
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    dfs(nums, used, current, result);
    return result;
  }
  void dfs(vector<int>& nums,
           vector<bool>& used,
           vector<int>& current,
           vector<vector<int>>& result)
  {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      current.push_back(nums[i]);
      dfs(nums, used, current, result);
      current.pop_back();
      used[i] = false;
    }
  }
};

TEST(leetcode47, solution)
{
  Solution solution;
  vector<int> nums = { 1, 1, 2 };
  vector<vector<int>> answer = { { 1, 1, 2 }, { 1, 2, 1 }, { 2, 1, 1 } };
  auto result = solution.permuteUnique(nums);
  EXPECT_EQ(answer, result);
}