/**
 * https://leetcode.cn/problems/jump-game-ii/description/
 * https://r07na4yqwor.feishu.cn/docx/VMqbdJnAnoWqhOxWdIXcH3J3ntk
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& jump_ability) {
    int n = jump_ability.size();
    int i = 0;
    int c = 0;
    while (i < n - 1) {
      int pre_max_index = 0;
      int cur_jump_ability = jump_ability[i];
      int next = i;
      for (int j = i; j <= i + cur_jump_ability; j++) {
        if (j + jump_ability[j] > pre_max_index) {
          next = j;
        }
      }
      i = next;
      c++;
    }
    return c;
  }
};