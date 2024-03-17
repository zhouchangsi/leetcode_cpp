/**
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/
 * https://ahym1n4sq5.feishu.cn/docx/TWXNdK1Wvo4WQfxazREcAfHfnrT
*/
#include <bits/stdc++.h>
using namespace std;

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