#include "leetcode.h"

class Solution {
 public:
  //   int trap(vector<int>& height) {
  //     int n = height.size();
  //     vector<int> left_max(n, 0), right_max(n, 0);
  //     for (int i = 1; i < n; i++) {
  //       left_max[i] = max(left_max[i - 1], height[i - 1]);
  //     }
  //     for (int i = n - 2; i >= 0; i--) {
  //       right_max[i] = max(right_max[i + 1], height[i + 1]);
  //     }
  //     int answer = 0;
  //     for (int i = 0; i < n; i++) {
  //       int current_height = height[i];
  //       int min_height = min(left_max[i], right_max[i]);
  //       if (min_height > current_height) {
  //         answer += min_height - current_height;
  //       }
  //     }
  //     return answer;
  //   }
  int trap(vector<int>& height) {
    int n = height.size();
    stack<int> monotonic_stack;
    int sum = 0;
    if (n < 3) return 0;
    for (int i = 0; i < n; i++) {
      while (!monotonic_stack.empty() &&
             height[i] > height[monotonic_stack.top()]) {
        int bottom_index = monotonic_stack.top();
        monotonic_stack.pop();
        // 找到左边界
        while (!monotonic_stack.empty() &&
               height[i] == height[monotonic_stack.top()]) {
          monotonic_stack.pop();
        }
        if (monotonic_stack.empty()) {
          break;
        }

        int w = i - monotonic_stack.top() - 1;
        int h = min(height[i], height[monotonic_stack.top()]) -
                height[bottom_index];
        sum += w * h;
      }
      monotonic_stack.push(i);
    }
  }
};