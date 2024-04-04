#include "leetcode/env.h"

class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> monotonic_stack;
    for (int i = n - 1; i >= 0; i--) {
      int current_price = prices[i];
      // Pop all elements that are greater than current_price.
      while (!monotonic_stack.empty() && monotonic_stack.top() > current_price) {
        monotonic_stack.pop();
      }
      answer[i] = current_price - (monotonic_stack.empty() ? 0 : monotonic_stack.top());
      monotonic_stack.push(current_price);
    }
    return answer;
  }
};
