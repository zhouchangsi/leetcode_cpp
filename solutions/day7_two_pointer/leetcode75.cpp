// https://leetcode-cn.com/problems/sort-colors/
// https://r07na4yqwor.feishu.cn/docx/XHgNdqxBPomkQoxo8hUcQrS5nfb
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& numbers) {
    int n = numbers.size();

    // i is the last index of 0
    int i = -1;
    for (int j = 0; j < n; ++j) {
      // 0 put to the left
      if (numbers[j] == 0) {
        i++;
        swap(numbers[i], numbers[j]);
      }
    }

    for (int j = i + 1; j < n; ++j) {
      // 1 put to after 0
      if (numbers[j] == 1) {
        i++;
        swap(numbers[i], numbers[j]);
      }
    }
  }
};