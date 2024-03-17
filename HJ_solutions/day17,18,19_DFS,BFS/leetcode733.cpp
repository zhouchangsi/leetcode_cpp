/**
 * https://leetcode.cn/problems/flood-fill/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  const int dx[4] = {1, 0, 0, -1};
  const int dy[4] = {0, 1, -1, 0};

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    int old_color = image[sr][sc];
    if (old_color == color) {
      return image;
    }
    int n = image.size(), m = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
      pair<int, int> xy = q.front();
      q.pop();
      image[xy.first][xy.second] = color;
      for (int i = 0; i < 4; i++) {
        int tx = xy.first + dx[i], ty = xy.second + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
        if (image[tx][ty] != old_color) continue;
        q.push({tx, ty});
      }
    }
    return image;
  }
};