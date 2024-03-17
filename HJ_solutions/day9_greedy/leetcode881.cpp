/**
 * https://leetcode.cn/problems/boats-to-save-people/description/
 * https://r07na4yqwor.feishu.cn/docx/QHDQd9ssIo2Ni0x20frcmd0qnac
*/
#include "../leetcode/env.h"


class Solution
{
public:
  int numRescueBoats(vector<int>& people, int limit)
  {
    sort(people.begin(), people.end());
    int lightest = 0, heaviest = people.size() - 1;
    int count = 0;
    while (lightest <= heaviest) {
      if (people[heaviest] + people[lightest] > limit) {
        heaviest--;
      } else {
        lightest++, heaviest--;
      }
      count++;
    }
    return count;
  }
};