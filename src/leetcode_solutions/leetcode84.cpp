#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> st;
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int h_top = heights[st.top()];
        st.pop();
        int left = st.top() + 1;
        int right = i - 1;
        ans = max(ans, h_top * (right - left + 1));
      }
      st.push(i);
    }
    return ans;
  }
};

TEST(leetcode84, 1) {
  Solution solution;
  {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = solution.largestRectangleArea(heights);
    EXPECT_EQ(result, 10);
  }
  {
    vector<int> heights = {2, 0};
    int result = solution.largestRectangleArea(heights);
    EXPECT_EQ(result, 2);
  }
}
