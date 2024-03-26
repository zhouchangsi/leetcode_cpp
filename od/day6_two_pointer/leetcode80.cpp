/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * https://ahym1n4sq5.feishu.cn/docx/VWIfdyejNoPxiXxIU3ScP0CKnEc
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int k = 2;  // 每个元素最多出现的次数
    if (nums.size() <= k)
      return nums.size();  // 如果数组长度小于等于 k，直接返回数组长度

    // 初始化慢指针和快指针
    int slow = k, fast = k;
    while (fast < nums.size()) {
      // 如果 nums[fast] 不等于 nums[slow - k]
      // 则将 nums[fast] 复制到 nums[slow]，并将 slow 向前移动一位
      if (nums[fast] !=
          nums[slow - k]) {  // nums[slow - k]
                             // 是当前考虑的元素在新数组中的第一个可能的位置
        nums[slow] = nums[fast];
        slow++;
      }
      // 将 fast 向前移动一位，以检查下一个元素
      fast++;
    }
    // 返回新数组的长度
    return slow;
  }
};

// class Solution
// {
// public:
//   int removeDuplicates(vector<int>& nums)
//   {
//     int n = nums.size();
//     if (n < 1)
//       return 0;
//     int last_assign = 0;
//     int repeat_count = 1;

//     for (int i = 1; i < nums.size(); i++) {
//       if (nums[i] == nums[last_assign]) {
//         if (repeat_count == 2) {
//           // find new element
//           while (i < nums.size() && nums[i] == nums[last_assign]) i++;
//           if (i >= nums.size()) break;
//           last_assign++;
//           nums[last_assign] = nums[i];
//           repeat_count = 1;
//         } else {
//           repeat_count++;
//           last_assign++;
//           nums[last_assign] = nums[i];
//         }
//       } else {
//         last_assign++;
//         nums[last_assign] = nums[i];
//         repeat_count = 1;
//       }
//     }
//     return last_assign + 1;
//   }
// };
