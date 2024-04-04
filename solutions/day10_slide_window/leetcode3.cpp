// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://r07na4yqwor.feishu.cn/docx/KKdmd5wzjoaP24x9xnAcYRbzndd
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> occ;
    const int n = s.size();
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
      occ.insert(s[r]);
      while (occ.size() < r - l + 1) {
        occ.erase(s[l]);
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};