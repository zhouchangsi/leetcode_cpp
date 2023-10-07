#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 0) {
      return 0;
    }
    sort(
        points.begin(), points.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int interval_right = points[0][1];
    int ans = 1;
    for (int i = 1; i < n; i++) {
      auto interval_left = points[i][0];
      if (interval_left > interval_right) {
        ans++;
        interval_right = points[i][1];
      }
    }
    return ans;
  }
};

TEST(leetcode452, solution) {
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  EXPECT_EQ(Solution().findMinArrowShots(points), 2);
  points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  EXPECT_EQ(Solution().findMinArrowShots(points), 4);
  points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  EXPECT_EQ(Solution().findMinArrowShots(points), 2);
  points = {{1, 2}};
  EXPECT_EQ(Solution().findMinArrowShots(points), 1);
  points = {{2, 3}, {2, 3}};
  EXPECT_EQ(Solution().findMinArrowShots(points), 1);
}