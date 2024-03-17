/**
 * https://leetcode.cn/problems/number-of-provinces/description/
 * https://og7kl7g6h8.feishu.cn/docx/A9PAdE2skoyThIxjVt5cA0hXnUh
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
    {
      parent[i] = i;
    }
    // find the root of the x
    function<int(int)> find = [&](int x)
    {
      if (parent[x] != x)
      {
        parent[x] = find(parent[x]);
      }
      return parent[x];
    };
    function<void(int, int)> merge = [&](int x, int y)
    {
      parent[find(x)] = find(y);
    };

    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < isConnected[i].size(); ++j)
      {
        if (isConnected[i][j] == 1)
        {
          merge(i, j);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      if (parent[i] == i)
      {
        ++ans;
      }
    }
    return ans;
  }
};
