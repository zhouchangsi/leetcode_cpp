#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    int m = grid.size();
    if (m == 0)
      return res;
    int n = grid[0].size();
    if (n == 0)
      return res;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
        ++res;
        dfs_to_set_zero(grid, i, j);
      }
    }
    return res;
  }
  void dfs_to_set_zero(vector<vector<char>>& grid, int i, int j) {
    grid[i][j] = '0';
    if (i - 1 >= 0 && grid[i - 1][j] == '1')
      dfs_to_set_zero(grid, i - 1, j);
    if (i + 1 < grid.size() && grid[i + 1][j] == '1')
      dfs_to_set_zero(grid, i + 1, j);
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
      dfs_to_set_zero(grid, i, j - 1);
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
      dfs_to_set_zero(grid, i, j + 1);
  }
};

TEST(leetcode200, solution) {
  vector<vector<char>> input;
  int res;
  Solution sln;

  input = {{'1', '1', '1', '1', '0'},
           {'1', '1', '0', '1', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '0', '0', '0'}};
  res = 1;
  ASSERT_EQ(sln.numIslands(input), res);

  input = {{'1', '1', '0', '0', '0'},
           {'1', '1', '0', '0', '0'},
           {'0', '0', '1', '0', '0'},
           {'0', '0', '0', '1', '1'}};
  res = 3;
  ASSERT_EQ(sln.numIslands(input), res);
}
