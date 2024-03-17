/**
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/ 
 */
#include "../leetcode/leetcode.h"

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (guess(m) <= 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};