// https://leetcode.cn/problems/teemo-attacking/description/
// https://r07na4yqwor.feishu.cn/docx/WdPDdaSWboaY2yxrMqfcis89nJg
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    if (n == 0) return 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += min(timeSeries[i] - timeSeries[i - 1], duration);
    }
    return ans + duration;
  }
};