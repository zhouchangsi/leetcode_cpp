#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
        return 0;
        }
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];
             });
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
        if (intervals[i][0] >= right) {
            ans++;
            right = intervals[i][1];
        }
        }
        return n - ans;
    }
};

TEST(leetcode435, solution) {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    EXPECT_EQ(Solution().eraseOverlapIntervals(intervals), 1);
    intervals = {{1, 2}, {1, 2}, {1, 2}};
    EXPECT_EQ(Solution().eraseOverlapIntervals(intervals), 2);
    intervals = {{1, 2}, {2, 3}};
    EXPECT_EQ(Solution().eraseOverlapIntervals(intervals), 0);
}