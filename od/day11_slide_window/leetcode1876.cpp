/*
 * https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/submissions/511029095/
 * https://r07na4yqwor.feishu.cn/docx/LBzsdw5VXo8oz9xmd7pciyrFnie
 */
#include "../leetcode/leetcode.h"

class Solution
{
public:
  int countGoodSubstrings(std::string s)
  {
    if (s.length() < 3) {
      return 0;
    }

    int ans = 0;
    std::unordered_map<char, int> cnt;

    // 初始化第一个窗口的字符计数
    for (int i = 0; i < 3; i++) {
      cnt[s[i]]++;
    }

    // 计算第一个窗口的结果
    if (cnt.size() == 3) {
      ans++;
    }

    for (int right = 3; right < s.length(); right++) {
      // A1
      char ch = s[right];
      cnt[ch]++;

      // A2
      int left = right - 3;
      char leftCh = s[left];
      cnt[leftCh]--;
      if (cnt[leftCh] == 0) {
        cnt.erase(leftCh);
      }

      // A3
      if (cnt.size() == 3) {
        ans++;
      }
    }

    return ans;
  }
};
