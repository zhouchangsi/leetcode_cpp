/**
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
 * https://r07na4yqwor.feishu.cn/docx/EiOzd1RuGoWTQhxPp5zcjN8HnDd
 */
#include "../leetcode.h"
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        auto len = vector<int>(n, 1);
        auto cnt = vector<int>(n, 1);
        int max_len = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] <= nums[j])
                {
                    continue;
                }
                if (len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (len[i] == len[j] + 1)
                {
                    cnt[i] += cnt[j];
                }
            }
            max_len = max(max_len, len[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (len[i] == max_len)
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};