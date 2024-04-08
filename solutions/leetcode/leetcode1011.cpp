/**
 * https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
*/
#include "../leetcode.h"

class Solution {
public:
    bool check(vector<int>& weights, int days, int capacity) {
        int need = 1, cur = 0;
        for (int weight : weights) {
            if (cur + weight > capacity) {
                ++need;
                cur = 0;
            }
            cur += weight;
        }
        return need <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()),
            r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(weights, days, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};