#include "./leetcode.h"

class Solution
{
public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> hash;
    for (auto x : nums)
      hash.insert(x); // 放入hash表中
    int res = 0;
    for (auto x : hash) {
      if (!hash.count(x - 1)) {
        int y = x; // 以当前数x向后枚举
        while (hash.count(y + 1))
          y++;
        res = max(res, y - x + 1); // 更新答案
      }
    }
    return res;
  }
};