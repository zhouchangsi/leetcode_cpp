// https://leetcode.com/problems/max-consecutive-ones/
// https://r07na4yqwor.feishu.cn/docx/SkUidiNifoGlPexrjcncPK2Qnpx
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_len = 0;
    int cur_len = 0;
    for (auto i : nums) {
      if (i == 1) {
        cur_len++;
      } else {
        max_len = max(max_len, cur_len);
        cur_len = 0;
      }
    }
    max_len = max(max_len, cur_len);
    return max_len;
  }
};
