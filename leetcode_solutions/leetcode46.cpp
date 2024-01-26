#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

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
    }
    for (auto n : nums) {
      if (find(path.begin(), path.end(), n) != path.end())
        continue;
      path.push_back(n);
      dfs(nums);
      path.pop_back();
    }
  }
};

TEST(leetcode46, solution) {
  //   MyQueue solution;
  //   vector<int> nums = {1, 2, 3};
  //   auto res = solution.permute(nums);
  //   EXPECT_EQ(res.size(), 6);
}