#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      int x = i, y = 0;
      int val = matrix[x][y];
      while (x < m && y < n) {
        if (matrix[x][y] != val) {
          return false;
        }
        ++x;
        ++y;
      }
    }

    for (int j = 1; j < n; ++j) {
      int x = 0, y = j;
      int val = matrix[x][y];
      while (x < m && y < n) {
        if (matrix[x][y] != val) {
          return false;
        }
        ++x;
        ++y;
      }
    }

    return true;
  }
};

TEST(leetcode766, solution) {
  Solution s;
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  EXPECT_EQ(s.isToeplitzMatrix(matrix), true);
}