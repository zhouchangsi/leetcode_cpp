/**
 * https://leetcode.cn/problems/increasing-triplet-subsequence/submissions/511231575/
 * https://r07na4yqwor.feishu.cn/docx/PwVzdLGHmoB4xcx5s9xcrTsingg
*/
#include "../leetcode/leetcode.h"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        auto greater_than_left = vector<bool>(n, false), less_than_right = vector<bool>(n, false);
        int min_val = nums[0], max_val = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            greater_than_left[i] = nums[i] > min_val;
            min_val = min(min_val, nums[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            less_than_right[i] = nums[i] < max_val;
            max_val = max(max_val, nums[i]);
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (greater_than_left[i] && less_than_right[i])
            {
                return true;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            } else if (num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;
    }
};