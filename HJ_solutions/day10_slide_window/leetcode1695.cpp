/**
 * https://leetcode.cn/problems/maximum-erasure-value/description/
 * https://r07na4yqwor.feishu.cn/docx/WIZKd5tVsoZP8xxzC83cEJEXnph
*/
#include "../leetcode/leetcode.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int l = 0, r = 0;

        int n = nums.size();
        int sum = 0;
        int max_sum = 0;
        while(r < n) {
            while(s.count(nums[r])) {
                s.erase(nums[l]);
                sum = sum - nums[l];
                l++;
            }
            s.emplace(nums[r]);
            sum += nums[r];
            max_sum = max(max_sum, sum);
            r++;
        }
        return max_sum;
    }
};