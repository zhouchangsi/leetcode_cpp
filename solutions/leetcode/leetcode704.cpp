/**
 * https://leetcode.cn/problems/binary-search/description/
 * https://r07na4yqwor.feishu.cn/docx/LP4odUMajo9PGOxzONiciAOJnaf
 */
#include "../leetcode.h"

class Solution
{
public:
  static int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    int mid = (left + right) >> 1;
    while (left < right)
    {
      if (nums[mid] == target)
        return mid;
      if (nums[mid] > target)
        right = mid - 1;
      if (nums[mid] < target)
        left = mid + 1;
      mid = (left + right) >> 1;
    }
    if (nums[left] == target)
      return left;
    else
      return -1;
  }
};