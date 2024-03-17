/**
 * https://leetcode.cn/problems/climbing-stairs/description/
 * https://r07na4yqwor.feishu.cn/docx/VCgEd8VVpoREJ0xTZ6icDZqVnMb
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
         int cur = 0, n_2 = 1, n_1 = 2;
        for(int i = 3; i <= n; i++) {
            cur = n_1 + n_2;
            n_2 = n_1;
            n_1 = cur;
        }
        return cur;
    }
};