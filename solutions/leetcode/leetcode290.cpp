// https://leetcode.com/problems/word-pattern/
// https://ahym1n4sq5.feishu.cn/docx/DelAduSDeoDAykxjnYwclo8Pn4d
#include "leetcode.h"

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
    stringstream ss(s);
    string y;
    for (int i = 0; i < pattern.size(); i++) {
      char x = pattern[i];
      if (!(ss >> y)) return false;
      if (p2s.count(x) && p2s[x] != y) return false;
      if (s2p.count(y) && s2p[y] != x) return false;
      p2s[x] = y;
      s2p[y] = x;
    }
    return !(ss >> y);  // check if there are remaining words in s
  }
};