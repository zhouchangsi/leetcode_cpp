/**
 * https://leetcode-cn.com/problems/valid-anagram/
 * https://ahym1n4sq5.feishu.cn/docx/QmYad7PaPoascwxUTDNcKf6ZnCb
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    vector<int> table(26, 0);
    for (auto& ch : s) {
      table[ch - 'a']++;
    }
    for (auto& ch : t) {
      table[ch - 'a']--;
      if (table[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};