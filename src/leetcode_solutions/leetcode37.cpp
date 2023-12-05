#include "common_headers.h"

using namespace std;

class Solution
{
public:
  void solveSudoku(vector<vector<char>>& board) { dfs(board, 0, 0, false); }
  void dfs(vector<vector<char>>& board, int row, int col, bool&& solved)
  {
    if (row == 9) {
      solved = true;
      return;
    }

    if (col == 9) {
      dfs(board, row + 1, 0, std::move(solved));
      return;
    }

    if (board[row][col] != '.') {
      dfs(board, row, col + 1, std::move(solved));
      return;
    }

    for (int i = 1; i <= 9; ++i) {
      if (!isValid(board, row, col, i)) {
        continue;
      }
      board[row][col] = i + '0';
      dfs(board, row, col + 1, std::move(solved));
      if (solved) {
        return;
      }
      board[row][col] = '.';
    }
  }

  bool isValid(vector<vector<char>>& board, int row, int col, int val)
  {
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == val + '0')
        return false;
    }

    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == val + '0')
        return false;
    }

    int r = row / 3 * 3;
    int c = col / 3 * 3;
    for (int i = r; i < r + 3; ++i) {
      for (int j = c; j < c + 3; ++j) {
        if (board[i][j] == val + '0')
          return false;
      }
    }

    return true;
  }
};

TEST(leetcode37, solution)
{
  Solution solution;
  vector<vector<char>> board = {
    { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
    { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
  };
  solution.solveSudoku(board);
  vector<vector<char>> expect = {
    { '5', '3', '4', '6', '7', '8', '9', '1', '2' },
    { '6', '7', '2', '1', '9', '5', '3', '4', '8' },
    { '1', '9', '8', '3', '4', '2', '5', '6', '7' },

    { '8', '5', '9', '7', '6', '1', '4', '2', '3' },
    { '4', '2', '6', '8', '5', '3', '7', '9', '1' },
    { '7', '1', '3', '9', '2', '4', '8', '5', '6' },

    { '9', '6', '1', '5', '3', '7', '2', '8', '4' },
    { '2', '8', '7', '4', '1', '9', '6', '3', '5' },
    { '3', '4', '5', '2', '8', '6', '1', '7', '9' },
  };
  EXPECT_EQ(board, expect);
}