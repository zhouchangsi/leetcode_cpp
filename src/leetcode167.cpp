#include "common_headers.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = (int)numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return {i + 1, j + 1};
            else if (sum < target)
                ++i;
            else
                --j;
        }
        return {-1, -1};
    }
};

TEST(leetcode167, solution) {
    Solution s;
    vector<int> nums;
    int target;

    nums = {2, 7, 11, 15};
    target = 9;
    ASSERT_EQ(s.twoSum(nums, target), vector<int>({1, 2}));

    nums = {2, 3, 4};
    target = 6;
    ASSERT_EQ(s.twoSum(nums, target), vector<int>({1, 3}));

    nums = {-1, 0};
    target = -1;
    ASSERT_EQ(s.twoSum(nums, target), vector<int>({1, 2}));
}