// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// https://ahym1n4sq5.feishu.cn/docx/AQwAd0mWdoz7UtxSqNAc7K9tnaf
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int slow = 1;
    for (int fast = 1; fast < n; fast++) {
      if (nums[fast] != nums[fast - 1]) {
        nums[slow] = nums[fast];
        slow++;
      }
    }
    return slow;
  }
};