/**
 * https://leetcode.cn/problems/circus-tower-lcci/description/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int bestSeqAtIndex(vector<int> &height, vector<int> &weight) {
    int n = height.size();
    vector<pair<int, int>> people(n);
    for (int i = 0; i < n; i++) {
      people[i] = {height[i], weight[i]};
    }
    sort(people.begin(), people.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first == b.first ? a.second > b.second : a.first < b.first;
         });

    vector<int> dp;  // 保存当前长度为i的最长递增子序列的末尾元素的最小值
    for (const auto &[h, w] : people) {
      // 找到第一个大于等于w的位置
      auto it = lower_bound(dp.begin(), dp.end(), w);
      if (it == dp.end()) {
        dp.push_back(w);
      } else {
        *it = w;
      }
    }
    return dp.size();
  }
};