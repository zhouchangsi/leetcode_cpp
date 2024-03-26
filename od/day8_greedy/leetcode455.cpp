/**
 * https://leetcode.cn/problems/assign-cookies/
 * https://r07na4yqwor.feishu.cn/docx/K25NdqbERosdGxxPSmZcwABEnGg
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int>& g, vector<int>& s)
  {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    const int m = g.size(), n = s.size();
    int c = 0;
    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
      while (j < n && g[i] > s[j]) {
        j++;
      }
      if (j < n) {
        c++;
      }
    }
    return c;
  }
};