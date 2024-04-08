/**
 * https://leetcode.cn/problems/fibonacci-number/description/
 * https://r07na4yqwor.feishu.cn/docx/C14gd8vXqoEr6DxgRoycJ4J6nab
*/

#include "../leetcode.h"
class Solution {
public:
    int fib(int n) {
        if (n == 0)            return 0;
        if (n == 1)            return 1;
        int n_2 = 0;
        int n_1 = 1;
        int fib_n = 0;
        for (int i = 2; i <= n; i++) {
            fib_n = n_2 + n_1;
            n_2 = n_1;
            n_1 = fib_n;
        }
        return fib_n;
    }
};