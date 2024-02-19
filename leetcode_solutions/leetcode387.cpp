#include "./leetcode/env.h"

class Solution
{
public:
  int firstUniqChar(string s)
  {
    unordered_map<char, int> map;
    for (const char& ch : s) {
      map[ch] = map.count(ch) == 0 ? 1 : map[ch] + 1;
    }
    for (int i = 0; i < s.size(); i++) {
      if (map[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};