// https://leetcode.com/problems/n-queens-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool is_valid(vector<vector<bool>>& board, int r, int c) {
    int n = board.size();
    for (int i = r - 1; i >= 0; i--) {
      if (board[i][c] == true) {
        return false;
      }
    }
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == true) {
        return false;
      }
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
      if (board[i][j] == true) {
        return false;
      }
    }
    return true;
  }
  int ans = 0;
  void dfs(vector<vector<bool>>& board, int row) {
    int n = board.size();
    if (row == n) {
      ans++;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (is_valid(board, row, i)) {
        board[row][i] = true;
        dfs(board, row + 1);
        board[row][i] = false;
      }
    }
  }
  int totalNQueens(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    dfs(board, 0);
    return ans;
  }
};