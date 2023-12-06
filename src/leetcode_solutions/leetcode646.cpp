#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int findLongestChain(vector<vector<int>>& pairs)
  {
    int n = pairs.size();
    if (n == 0)
      return 0;
    // [[1,2],[7,8],[4,5]] -> [[1,2],[4,5],[7,8]]
    sort(
      pairs.begin(),
      pairs.end(),
      [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    vector<int> dp(n, 1);
    int max_len = 1;
    for (int i = 1; i < n; ++i) {
      int max_prev = 0;
      for (int j = 0; j < i; ++j) {
        if (pairs[j][1] < pairs[i][0]) {
          max_prev = max(max_prev, dp[j]);
        }
      }
      dp[i] = max_prev + 1;
      max_len = max(max_len, dp[i]);
    }

    return max_len;
  }
};

TEST(leetcode646, solution) {}