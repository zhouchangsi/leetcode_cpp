/**
 * https://leetcode.cn/problems/lemonade-change/submissions/509991500/
 * https://r07na4yqwor.feishu.cn/docx/FW37dJAfgo49iXxZnmccPmDinWc
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool lemonadeChange(vector<int>& bills)
  {
    // 20 = 10,5 || 5,5,5
    // 10 = 5
    unordered_map<int, int> count = { { 5, 0 }, { 10, 0 }, { 20, 0 } };

    for (auto bill : bills) {
      if (bill == 5) {
        count[5]++;
      }

      if (bill == 10) {
        if (count[5] < 1) {
          return false;
        }
        count[10]++, count[5]--;
      }

      if (bill == 20) {
        bool can_bill = false;
        if (count[5] > 0 && count[10] > 0) {
          count[5]--, count[10]--;
          can_bill = true;
        } else if (count[5] > 2) {
          count[5] -= 3;
          can_bill = true;
        }
        if (!can_bill) {
          return false;
        }
      }
    }

    return true;
  }
};

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