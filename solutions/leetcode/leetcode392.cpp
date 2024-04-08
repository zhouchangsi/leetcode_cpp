// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        ++i;
        ++j;
      } else {
        ++j;
      }
    }
    return i == s.size();
  }
};

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    auto i = s.begin();
    auto j = t.begin();
    while (i != s.end() && j != t.end()) {
      if (*i == *j) ++i;
      ++j;
    }
    return i == s.end();
  }
};