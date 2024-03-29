// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
// https://r07na4yqwor.feishu.cn/docx/GhfkdsrOqopiJCxg3AucaphtnQf
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = (int)numbers.size() - 1;
    while (i < j) {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
        return {i + 1, j + 1};
      else if (sum < target)
        ++i;
      else
        --j;
    }
    return {-1, -1};
  }
};
