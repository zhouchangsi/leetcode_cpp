#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int m = 0, res = 0;
    for (int i = 0; i < arr.size(); i++) {
      m = max(m, arr[i]);
      if (m == i) {
        res++;
      }
    }
    return res;
  }
};

TEST(leetcode769, case1) {
  Solution solution;
  vector<int> vec = {4, 3, 2, 1, 0};
  int res = solution.maxChunksToSorted(vec);
  EXPECT_EQ(res, 1);
}