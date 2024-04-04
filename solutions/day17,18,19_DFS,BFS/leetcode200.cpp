/**
 * https://leetcode-cn.com/problems/number-of-islands/
 * https://og7kl7g6h8.feishu.cn/docx/E4pSd20NEoJK2Ux3BrjcncKbn1d
 */
#include "../leetcode/leetcode.h"

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
