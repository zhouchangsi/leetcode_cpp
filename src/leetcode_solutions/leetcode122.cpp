#include "common_headers.h";
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

TEST(leetcode122, case1) {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(Solution().maxProfit(prices), 7);
}