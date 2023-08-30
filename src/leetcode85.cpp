#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size();
    int m = n > 0 ? matrix[0].size() : 0;
    cout << n << " " << m << endl;
    int maxAns = 0;
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
      }

      cout << "heights: ";
      for (auto h : heights) cout << h << " ";
      cout << endl;

      int current_row_max_area = largestRectangleArea(heights);
      maxAns = max(maxAns, current_row_max_area);
    }
    return maxAns;
  }

  int largestRectangleArea(const vector<int>& heights) {
    int ans = 0;
    // deep copy heights
    vector<int> _heights;
    _heights.resize(heights.size());
    copy(heights.cbegin(), heights.cend(), _heights.begin());
    _heights.insert(heights.begin(), 0);
    _heights.push_back(0);
    stack<int> st;
    for (int i = 0; i < _heights.size(); ++i) {
      while (!st.empty() && _heights[i] < _heights[st.top()]) {
        int h_top = _heights[st.top()];
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

TEST(leetcode85, leetcode85) {
  Solution solution;
  {
    vector<vector<char>> input = {{'1', '0', '1', '0', '0'},
                                  {'1', '0', '1', '1', '1'},
                                  {'1', '1', '1', '1', '1'},
                                  {'1', '0', '0', '1', '0'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 6);
  }
  {
    vector<vector<char>> input = {};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 0);
  }
  {
    vector<vector<char>> input = {{'0'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 0);
  }
  {
    vector<vector<char>> input = {{'1'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 1);
  }
  {
    vector<vector<char>> input = {{'0', '0'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 0);
  }
  {
    vector<vector<char>> input = {{'1', '0'}, {'1', '0'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 2);
  }
}