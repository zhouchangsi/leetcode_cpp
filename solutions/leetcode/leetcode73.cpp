#include <bits/stdc++.h>
using namespace std;


// o(n+m) space
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    unordered_set<int> rows, cols;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          rows.insert(i);
          cols.insert(j);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (rows.count(i) || cols.count(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};


// o(1) space
// https://leetcode.cn/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-100-liked
