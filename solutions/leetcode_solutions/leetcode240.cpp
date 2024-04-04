class Solution {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();     // n行
    int m = matrix[0].size();  // m列
    if (n == 0) return false;
    if (m == 0) return false;
    int i = 0;
    int j = m - 1;
    while (i < n && j >= 0) {
      if (matrix[i][j] > target) {
        j = j - 1;
      } else if (matrix[i][j] < target) {
        i = i + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};