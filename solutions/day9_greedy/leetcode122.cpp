/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * https://r07na4yqwor.feishu.cn/docx/Fk9GdJqOroTPTRx5iTpcMrkYnFe
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    }

    int multi_day_profit = 0;
    for (int i = 1; i < n; i++) {
      auto daily_profit = prices[i] - prices[i - 1];
      multi_day_profit += max(0, daily_profit);
    }
    return multi_day_profit;
  }
};
