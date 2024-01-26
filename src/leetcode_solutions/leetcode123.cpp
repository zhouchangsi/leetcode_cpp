#include "common_headers.h"

using namespace std;

class Solution
{

  class enum State
  {
    not_hold_and_no_transaction,
    not_hold_and_one_transaction,
    not_hold_and_two_transaction,
    hold_and_no_transaction,
    hold_and_one_transaction,
    hold_and_two_transaction,
  };

public:
  int maxProfit(vector<int>& prices)
  {
    if (prices.size() <= 1)
      return 0;

    int dp[prices.size()][6];
    dp[0][State::not_hold_and_no_transaction] = 0;
    dp[0][State::not_hold_and_one_transaction] = 0;
    dp[0][State::not_hold_and_two_transaction] = 0;
    dp[0][State::hold_and_no_transaction] = -prices[0];
    dp[0][State::hold_and_one_transaction] = -prices[0];
    dp[0][State::hold_and_two_transaction] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      dp[i][State::not_hold_and_no_transaction] = 0;

        
      dp[i][State::not_hold_and_one_transaction] = max(dp[i - 1][State::not_hold_and_one_transaction], dp[i - 1][State::hold_and_no_transaction] + prices[i]);
             dp[i][State::not_hold_and_two_transaction] =
        max(dp[i - 1][State::not_hold_and_two_transaction],
            dp[i - 1][State::hold_and_one_transaction] + prices[i]);
      dp[i][State::hold_and_no_transaction] =
        max(dp[i - 1][State::hold_and_no_transaction],
            dp[i - 1][State::not_hold_and_no_transaction] - prices[i]);
      dp[i][State::hold_and_one_transaction] =
        max(dp[i - 1][State::hold_and_one_transaction],
            dp[i - 1][State::not_hold_and_one_transaction] - prices[i]);
      dp[i][State::hold_and_two_transaction] =
        dp[i - 1][State::not_hold_and_two_transaction] - prices[i];
    }

    return max(dp[prices.size() - 1][State::not_hold_and_no_transaction],
               max(dp[prices.size() - 1][State::not_hold_and_one_transaction],
                   dp[prices.size() - 1][State::not_hold_and_two_transaction]));
  }
};

TEST(leetcode123, solution) {}