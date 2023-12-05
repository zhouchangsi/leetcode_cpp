#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>>& grid)
  {
    int max_area = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          int area = 0;
          dfs(grid, visited, i, j, area);
          max_area = max(max_area, area);
        }
      }
    }

    return max_area;
  }
  void dfs(vector<vector<int>>& grid,
           vector<vector<bool>>& visited,
           int i,
           int j,
           int& area)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        visited[i][j] || grid[i][j] == 0) {
      return;
    }

    visited[i][j] = true;
    area++;
    dfs(grid, visited, i - 1, j, area);
    dfs(grid, visited, i + 1, j, area);
    dfs(grid, visited, i, j - 1, area);
    dfs(grid, visited, i, j + 1, area);
  }
};

TEST(leetcode695, solution)
{
  {
    Solution s;
    vector<vector<int>> grid = { { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
                                 { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                                 { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                                 { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
                                 { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
                                 { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                                 { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 } };
    int res = s.maxAreaOfIsland(grid);
    ASSERT_EQ(res, 6);
  }
  {
    Solution s;
    vector<vector<int>> grid = { { 0, 0, 0, 0, 0, 0, 0, 0 } };
    int res = s.maxAreaOfIsland(grid);
    ASSERT_EQ(res, 0);
  }
}