/**
 * https://leetcode-cn.com/problems/koko-eating-bananas/
*/
#include "../leetcode/leetcode.h"
#include <math.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = pow(10, 9);
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(piles, h, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
    bool check(vector<int>& piles, int h, int k) {
        int time = 0;
        for (auto p : piles) time += (p - 1) / k + 1;
        return time <= h;
    }
};