// https://leetcode.com/problems/longest-harmonious-subsequence/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto i : nums) {
      m[i]++;
    }

    int max_len = 0;
    for (auto i : m) {
      if (m.find(i.first + 1) != m.end()) {
        max_len = max(max_len, i.second + m[i.first + 1]);
      }
    }

    return max_len;
  }
};
