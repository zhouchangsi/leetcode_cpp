// https://leetcode.com/problems/container-with-most-water/
// https://r07na4yqwor.feishu.cn/docx/WcAVdEBD5o8DhQxIqkccvDZqnHh
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int max_area = 0;
    while (l < r) {
      const int w = r - l;
      const int h = min(height[l], height[r]);
      max_area = max(max_area, w * h);
      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }
    return max_area;
  }
};