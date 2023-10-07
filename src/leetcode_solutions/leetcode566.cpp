#include "common_headers.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c) {
      return mat;
    }

    vector<vector<int>> res(r, vector<int>(c));

    for (int i = 0; i < m * n; ++i) {
      res[i / c][i % c] = mat[i / n][i % n];
    }

    return res;
  }
};

TEST(leetcode566, case1) {
  Solution s;
  vector<vector<int>> mat = {{1, 2}, {3, 4}};
  vector<vector<int>> res = {{1, 2, 3, 4}};
  EXPECT_EQ(s.matrixReshape(mat, 1, 4), res);
}