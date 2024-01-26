#include "./leetcode/env.h"

class Solution
{
public:
  int wiggleMaxLength(vector<int>& nums)
  {
    if (nums.size() < 2) {
      return nums.size();
    }

    // 关键是看方向的变化，如果方向变化了，那么就是一个峰或者谷
    int prev_diff = nums[1] - nums[0];
    int res = prev_diff != 0 ? 2 : 1;
    for (int i = 2; i < nums.size(); i++) {
      int diff = nums[i] - nums[i - 1];
      // 只要方向变化了， 就是一个峰或者谷， 那么就可以加1
      if ((diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0)) {
        res++;
        prev_diff = diff;
      }
    }

    return res;
  }
};

int
main()
{
  // case 1
  {
    vector<int> nums = { 1, 7, 4, 9, 2, 5 };
    int res = Solution().wiggleMaxLength(nums);
    assert(res == 6);
  }
  {
    vector<int> nums = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    int res = Solution().wiggleMaxLength(nums);
    assert(res == 7);
  }
  {
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int res = Solution().wiggleMaxLength(nums);
    assert(res == 2);
  }

  return 0;
}