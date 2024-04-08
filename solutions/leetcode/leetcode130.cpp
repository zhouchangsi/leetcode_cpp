#include "common_headers.h"

class Solution
{
public:
  void solve(vector<vector<char>>& board)
  {
    int m = board.size();
    int n = board[0].size();
    // marked[i][j] 表示 (i, j) 是否被标记过, 如果被标记过, 则表示 (i, j)
    // 与边界上的 'O' 相连
    vector<vector<bool>> marked(m, vector<bool>(n, false));
    vector<vector<int>> directions = {
      { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
    };

    function<void(int, int)> dfs = [&](int x, int y) {
      marked[x][y] = true;
      for (auto& direction : directions) {
        int nx = x + direction[0];
        int ny = y + direction[1];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O' &&
            !marked[nx][ny]) {
          dfs(nx, ny);
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O' && !marked[i][0]) {
        dfs(i, 0);
      }
      if (board[i][n - 1] == 'O' && !marked[i][n - 1]) {
        dfs(i, n - 1);
      }
    }

    for (int j = 0; j < n; ++j) {
      if (board[0][j] == 'O' && !marked[0][j]) {
        dfs(0, j);
      }
      if (board[m - 1][j] == 'O' && !marked[m - 1][j]) {
        dfs(m - 1, j);
      }
    }

    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == 'O' && !marked[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }
};

TEST(leetcode130, solution)
{
  Solution solution;
  vector<vector<char>> board = {
    { 'X', 'X', 'X', 'X' },
    { 'X', 'O', 'O', 'X' },
    { 'X', 'X', 'O', 'X' },
    { 'X', 'O', 'X', 'X' },
  };
  vector<vector<char>> expected = {
    { 'X', 'X', 'X', 'X' },
    { 'X', 'X', 'X', 'X' },
    { 'X', 'X', 'X', 'X' },
    { 'X', 'O', 'X', 'X' },
  };
  solution.solve(board);
  ASSERT_EQ(board, expected);
}