#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if (n <= 0 || k <= 0) {
      return res;
    }
    vector<int> path;
    dfs(n, k, 1, path, res);
    return res;
  }
  void dfs(int n,
           int k,
           int start,
           vector<int>& path,
           vector<vector<int>>& res) {
    if (path.size() + (n - start + 1) < k) {
      return;
    }

    if (path.size() == k) {
      res.push_back(path);
      return;
    }

    if (start == n + 1) {
      return;
    }
    path.emplace_back(start);
    dfs(n, k, start + 1, path, res);
    path.pop_back();
    dfs(n, k, start + 1, path, res); 
  }
};

TEST(leetcode77, solution) {
  {
    int n = 4;
    int k = 2;
    Solution solution;
    vector<vector<int>> res = solution.combine(n, k);
    vector<vector<int>> expect = {{2, 4}, {3, 4}, {2, 3},
                                  {1, 2}, {1, 3}, {1, 4}};
    multiset<vector<int>> s(res.begin(), res.end());
    multiset<vector<int>> e(expect.begin(), expect.end());
    EXPECT_EQ(s, e);
  }
  {
    int n = 1;
    int k = 1;
    Solution solution;
    vector<vector<int>> res = solution.combine(n, k);
    vector<vector<int>> expect = {{1}};
    multiset<vector<int>> s(res.begin(), res.end());
    multiset<vector<int>> e(expect.begin(), expect.end());
    EXPECT_EQ(s, e);
  }
}