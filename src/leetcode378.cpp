#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      int num_less_than_the_mid = 0;
      for (int i = 0; i < n; i++) {
        int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) -
                  matrix[i].begin();
        num_less_than_the_mid += pos;
      }
      if (num_less_than_the_mid < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

TEST(leetcode378, case1) {
  Solution s;
  vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  EXPECT_EQ(s.kthSmallest(matrix, 8), 13);
}