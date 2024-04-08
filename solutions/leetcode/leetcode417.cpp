#include "common_headers.h"

using namespace std;

class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
  {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    vector<vector<int>> directions = {
      { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
    };

    function<void(int, int, vector<vector<bool>>&)> dfs =
      [&](int x, int y, vector<vector<bool>>& marked) {
        marked[x][y] = true;
        for (auto& direction : directions) {
          int nx = x + direction[0];
          int ny = y + direction[1];
          if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
              heights[nx][ny] >= heights[x][y] && !marked[nx][ny]) {
            dfs(nx, ny, marked);
          }
        }
      };

    // 标记可以到达太平洋的点
    for (int i = 0; i < m; ++i) {
      if (!pacific[i][0]) {
        dfs(i, 0, pacific);
      }
      if (!atlantic[i][n - 1]) {
        dfs(i, n - 1, atlantic);
      }
    }

    // 标记可以到达大西洋的点
    for (int j = 0; j < n; ++j) {
      if (!pacific[0][j]) {
        dfs(0, j, pacific);
      }
      if (!atlantic[m - 1][j]) {
        dfs(m - 1, j, atlantic);
      }
    }

    vector<vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({ i, j });
        }
    }
    return result;
  }
};

TEST(leetcode417, solution)
{
  Solution solution;
  vector<vector<int>> heights = { { 1, 2, 2, 3, 5 },
                                  { 3, 2, 3, 4, 4 },
                                  { 2, 4, 5, 3, 1 },
                                  { 6, 7, 1, 4, 5 },
                                  { 5, 1, 1, 2, 4 } };
  vector<vector<int>> expected = { { 0, 4 }, { 1, 3 }, { 1, 4 }, { 2, 2 },
                                   { 3, 0 }, { 3, 1 }, { 4, 0 } };
  auto result = solution.pacificAtlantic(heights);
  EXPECT_EQ(result, expected);
}