#include "leetcode.h"

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> monotonic_stack;
    for (int i = 0; i < n; i--) {
      int current_temperature = temperatures[i];
      while (!monotonic_stack.empty() && temperatures[monotonic_stack.top()] < current_temperature) {
        int index = monotonic_stack.top();
        monotonic_stack.pop();
        answer[index] = i - index;
      }
      monotonic_stack.push(i);
    }
    return answer;
  }
};