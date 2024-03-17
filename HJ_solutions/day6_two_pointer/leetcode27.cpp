/**
 * https://leetcode.cn/problems/remove-element/description/
 * https://ahym1n4sq5.feishu.cn/docx/Q38XdytUAoUv6Oxf6Zscb2Bzn0e
*/
#include "../leetcode/env.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while(fast < nums.size()) {
            if(nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};