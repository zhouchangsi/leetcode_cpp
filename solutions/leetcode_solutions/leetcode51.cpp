#include <cassert>

#include "./leetcode/env.h"

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, ans);
    return ans;
  }

 private:
  void backtrack(vector<string>& board, int row, vector<vector<string>>& ans) {
    int n = board.size();
    if (row == n) {
      ans.push_back(board);
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (!is_valid(board, row, col)) {
        continue;
      }
      board[row][col] = 'Q';
      backtrack(board, row + 1, ans);
      board[row][col] = '.';
    }
  }

  bool is_valid(vector<string>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
      // check row
      if (row - i >= 0 && board[row - i][col] == 'Q') {
        return false;
      }
      // check left top
      if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') {
        return false;
      }
      // check right top
      if (row - i >= 0 && col + i < n && board[row - i][col + i] == 'Q') {
        return false;
      }
    }

    return true;
  }
};

int main() {
  // case 1
  {
    auto ans = Solution().solveNQueens(4);
    assert(ans.size() == 2);
  }
  // case 2
  {
    auto ans = Solution().solveNQueens(1);
    assert(ans.size() == 1);
  }
  return 0;
}