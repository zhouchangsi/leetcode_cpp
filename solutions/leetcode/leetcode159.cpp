// https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    const int& n = s.size();
    unordered_map<char, int> m;
    int l = 0, r = 0;
    int max_len = 1;
    while (r < n) {
      m[s[r]]++;
      while (m.size() > 2) {
        m[s[l]]--;
        if (m[s[l]] == 0) {
          m.erase(s[l]);
        }
        l++;
      }
      max_len = max(max_len, r - l + 1);
      r++;
    }
    return max_len;
  }
};