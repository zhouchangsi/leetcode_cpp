#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    auto get_pos = [&](int i, int j) { return make_pair(j, -i + n - 1); };
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - 1 - i; j++) {
        auto [x1, y1] = get_pos(i, j);
        auto [x2, y2] = get_pos(x1, y1);
        auto [x3, y3] = get_pos(x2, y2);
        auto [x4, y4] = get_pos(x3, y3);
        // clang-format off
        tie(         matrix[x1][y1], matrix[x2][y2], matrix[x3][y3], matrix[x4][y4])
        = make_tuple(matrix[x4][y4], matrix[x1][y1], matrix[x2][y2], matrix[x3][y3]);
        // clang-format on
      }
    }
  }
};