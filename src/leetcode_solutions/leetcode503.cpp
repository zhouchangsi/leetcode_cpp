#include "common_headers.h"

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;
    for (int i = 0; i < n * 2 - 1; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
        ans[stk.top()] = nums[i % n];
        stk.pop();
      }
      stk.push(i % n);
    }
    return ans;
  }
};

TEST(leetcode503, case1) {
  Solution s;
  vector<int> nums{1, 2, 1};
  vector<int> expect{2, -1, 2};
  EXPECT_EQ(s.nextGreaterElements(nums), expect);
}