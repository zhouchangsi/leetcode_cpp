/**
 * https://leetcode.cn/problems/grumpy-bookstore-owner/description/
 * https://r07na4yqwor.feishu.cn/docx/YYCqdGWOZofqI8xlTtjcUXz2nAf
 */

#include "../leetcode/leetcode.h"

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum_no_calmness = 0;
        for (int i = 0; i < n; i++) {
            sum_no_calmness += customers[i] * (grumpy[i] ^ 1);
        }

        int effect = 0;
        for (int i = 0; i < minutes; i++) {
            effect += customers[i] * grumpy[i];
        }
        int max_effect = effect;
        for (int l = 0, r = minutes; r < n; l++, r++) {
            effect += grumpy[r]  * customers[r];
            effect -= grumpy[l] * customers[l];
            max_effect = max(max_effect, effect);
        }
        return sum_no_calmness + max_effect;
    }
};