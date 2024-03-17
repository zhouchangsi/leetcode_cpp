#include "../leetcode/env.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 1;
        for(int fast = 1; fast < n; fast++) {
            if(nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};