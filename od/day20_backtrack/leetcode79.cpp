// https://leetcode.cn/problems/word-search/submissions/499807742/
// https://k9oaio5xpn.feishu.cn/docx/I794d4XD0oBGLHxbeoMcR1v5n4d
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>>& board, string word)
  {
    int m = board.size(), n = board[0].size(), len = word.size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    function<bool(int, int, int)> dfs = [&](int r, int c, int k) {
      if (k == len)
        return true;
      // 如果当前位置不合法，或者已经访问过，或者当前位置的字符不匹配，返回false
      if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] ||
          board[r][c] != word[k])
        return false;

      visited[r][c] = true;

      // 从当前位置出发，向四个方向搜索
      if (dfs(r - 1, c, k + 1) || dfs(r + 1, c, k + 1) || dfs(r, c - 1, k + 1) || dfs(r, c + 1, k + 1)) {
         return true;
      }
      visited[r][c] = false;
      return false;
    };
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (dfs(i, j, 0))
          return true;
    return false;
  }
};