/**
 * https://r07na4yqwor.feishu.cn/docx/Z1ZrdMUoeoPN6KxS1UhcvDYynqg
 * https://leetcode.cn/problems/jump-game/submissions/446153578/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int max_distance = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > max_distance) return false;
      int cur_distance = i + nums[i];
      max_distance = max(max_distance, cur_distance);
    }
    return true;
  }
};