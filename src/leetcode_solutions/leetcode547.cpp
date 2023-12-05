#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int findCircleNum(vector<vector<int>>& isConnected)
  {
    int n = isConnected.size();
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    function<int(int)> find = [&](int x) {
      if (parent[x] != x) {
        parent[x] = find(parent[x]);
      }
      return parent[x];
    };

    function<void(int, int)> merge = [&](int x, int y) {
      parent[find(x)] = find(y);
    };

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < isConnected[i].size(); ++j) {
        if (isConnected[i][j] == 1) {
          merge(i, j);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (parent[i] == i) {
        ++ans;
      }
    }
    return ans;
  }
};

TEST(leetcode547, solution)
{
  {
    Solution solution;
    vector<vector<int>> isConnected = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
    int ans = solution.findCircleNum(isConnected);
    ASSERT_EQ(ans, 2);
  }
  {
    Solution solution;
    vector<vector<int>> isConnected = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    int ans = solution.findCircleNum(isConnected);
    ASSERT_EQ(ans, 3);
  }
}