/**
 * https://leetcode.cn/problems/permutations-ii/
 * https://r07na4yqwor.feishu.cn/docx/Uk3Dd9KReoZ0I6xA3xectjwvnEe
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());

    function<void()> dfs = [&]() {
      if (current.size() == nums.size()) {
        result.push_back(current);
        return;
      }

      for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        dfs();
        current.pop_back();
        used[i] = false;
      }
    };

    dfs();
    return result;
  }
};
