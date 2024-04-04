// https://leetcode-cn.com/problems/non-overlapping-intervals/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 0) {
      return 0;
    }
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] >= right) {
        ans++;
        right = intervals[i][1];
      }
    }
    return n - ans;
  }
};