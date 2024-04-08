/**
 * https://r07na4yqwor.feishu.cn/docx/MvaqdNRS6o05bzxDP8DceuMkn2d
 * https://leetcode.cn/problems/fruit-into-baskets/submissions/510293299/
 */
#include "../leetcode.h"

class Solution
{
public:
  int totalFruit(vector<int>& fruits)
  {
    int n = fruits.size();
    int l = 0, r = 0;
    int max_count = 0;

    unordered_map<int, int> h;

    while (r < n) {
      ++h[fruits[r]];
      while (h.size() > 2) {
        auto it = h.find(fruits[l]);
        --it->second;
        if(it->second == 0) h.erase(it);
        ++l;
      }
      max_count = max(max_count, r - l + 1);
      ++r;
    }
    return max_count;
  }
};