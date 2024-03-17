/**
 * https://leetcode-cn.com/problems/contains-duplicate/
 * https://ahym1n4sq5.feishu.cn/docx/BzMddLEvfolr3ax2MxNcGbC4nbh
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto i : nums) {
      if (s.find(i) != s.end()) {
        return true;
      }
      s.insert(i);
    }
    return false;
  }
};