/**
 * https://leetcode.cn/problems/candy/description/
 * https://r07na4yqwor.feishu.cn/docx/K25NdqbERosdGxxPSmZcwABEnGg
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 1) {
      return 1;
    }
    vector<int> candy_count(n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candy_count[i] = candy_count[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candy_count[i] = max(candy_count[i], candy_count[i + 1] + 1);
      }
    }
    return accumulate(candy_count.begin(), candy_count.end(),
                      0);  // #include <numric>
  }
};