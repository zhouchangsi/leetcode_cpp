#include "./leetcode/env.h"

class Solution
{
private:
  vector<vector<int>> f;
  vector<vector<string>> ret;
  vector<string> ans;
  int n;

public:
  void dfs(const string& s, int left)
  {
    if (left == n) {
      ret.push_back(ans);
      return;
    }
    for (int right = left; right < n; ++right) {
      if (f[left][right]) {
        ans.push_back(s.substr(left, right - left + 1));
        dfs(s, right + 1);
        ans.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    n = s.size();
    // f[i][j]表示s[i..j]是否为回文串, 默认为true, 因为单个字符也是回文串
    f.assign(n, vector<int>(n, true));

    for (int left = n - 1; left >= 0; --left) {
      for (int right = left + 1; right < n; ++right) {
        // 如果f[left][right]为true，那么f[left + 1][right - 1]一定为true
        f[left][right] = (s[left] == s[right]) && f[left + 1][right - 1];
      }
    }

    dfs(s, 0);
    return ret;
  }
};