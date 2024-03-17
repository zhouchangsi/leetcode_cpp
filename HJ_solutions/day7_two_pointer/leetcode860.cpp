/**
 * https://r07na4yqwor.feishu.cn/docx/FW37dJAfgo49iXxZnmccPmDinWc
 */
#include "../leetcode/env.h"

class Solution
{
public:
  bool lemonadeChange(vector<int>& bills)
  {
    int five = 0, ten = 0;
    for (int b : bills) {
      if (b == 5) five++; // 无需找零
      else if (b == 10) five--, ten++; // 返还 5
      else if (ten) five--, ten--; // 此时 b=20，返还 10+5
      else five -= 3; // 此时 b=20，返还 5+5+5
      if (five < 0) return false; // 无法正确找零
    }
    return true;
  }
};