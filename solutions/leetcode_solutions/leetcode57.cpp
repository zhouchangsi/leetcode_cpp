// https://leetcode-cn.com/problems/insert-interval/
#include "./leetcode/env.h"

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,  //
                             vector<int>& interval            //
  ) {
    int n = intervals.size();
    vector<vector<int>> result;
    int i = 0;
    // 1. 先将小于插入区间的区间放入结果中
    while (i < n && intervals[i][1] < interval[0]) {
      result.push_back(intervals[i++]);
    }
    // 2. 将插入区间放入结果中
    while (i < n && intervals[i][0] <= interval[1]) {
      interval[0] = min(interval[0], intervals[i][0]);
      interval[1] = max(interval[1], intervals[i][1]);
      i++;
    }
    result.push_back(interval);
    // 3. 将大于插入区间的区间放入结果中
    while (i < n) {
      result.push_back(intervals[i++]);
    }

    return result;
  }
};