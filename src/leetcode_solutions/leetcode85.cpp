#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  // https://leetcode.cn/problems/maximal-rectangle/description/
  int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) {
      return 0;
    }
    int n = matrix[0].size();
    vector<vector<int>> left(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
        }
      }
    }

    int ret = 0;
    for (int j = 0; j < n; j++) {  // 对于每一列，使用基于柱状图的方法
      vector<int> up(m, 0), down(m, 0);

      stack<int> stk;
      for (int i = 0; i < m; i++) {
        while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
          stk.pop();
        }
        up[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
      }
      stk = stack<int>();
      for (int i = m - 1; i >= 0; i--) {
        while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
          stk.pop();
        }
        down[i] = stk.empty() ? m : stk.top();
        stk.push(i);
      }

      for (int i = 0; i < m; i++) {
        int height = down[i] - up[i] - 1;
        int area = height * left[i][j];
        ret = max(ret, area);
      }
    }
    return ret;
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
    vector<vector<char>> input = {{'0'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 0);
  }
  {
    vector<vector<char>> input = {{'1'}};
    const int output = solution.maximalRectangle(input);
    EXPECT_EQ(output, 1);
  }
}