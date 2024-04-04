#include "common_headers.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(k, n, 1, path, res);
        return res;
    }

    void dfs(int k, int n, int start, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k) {
            if (n == 0) {
                res.push_back(path);
            }
            return;
        }

        if (start == 10) {
            return;
        }

        if (n < start) {
            return;
        }

        path.push_back(start);
        dfs(k, n - start, start + 1, path, res);
        path.pop_back();
        dfs(k, n, start + 1, path, res);
    }
};

TEST(leetcode216, solution) {
    Solution solution;
    int k = 3;
    int n = 7;
    vector<vector<int>> res = solution.combinationSum3(k, n);
    vector<vector<int>> expect = {{1, 2, 4}};
    multiset<vector<int>> s(res.begin(), res.end());
    multiset<vector<int>> e(expect.begin(), expect.end());
    EXPECT_EQ(s, e);
}