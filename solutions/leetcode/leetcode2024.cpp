/**
 * https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/submissions/510318192/
 * https://r07na4yqwor.feishu.cn/docx/PoZidiDkpoan9qxfhENce5TEn6b
*/
#include "../leetcode.h"

class Solution
{
public:
  int maxConsecutiveAnswers(string answerKey, int k)
  {
    int max_count = 0;
    int l = 0, r = 0;
    int n = answerKey.size();
    int ct = 0, cf = 0;
    while (r < n) {
      answerKey[r] == 'T' ? ct++ : cf++;
      while (min(cf, ct) > k) {
        answerKey[l++] == 'T' ? ct-- : cf--;
      }
      max_count = max(max_count, r - l + 1);
      r++;
    }

    return max_count;
  }
};