/**
 * https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/
 * https://r07na4yqwor.feishu.cn/docx/OjkSdt54QoBj2nxNPz1cOG44nMb
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int mut_depth = 0;
        for (auto c : s) {
            if (c == '(') {
                mut_depth++;
                max_depth = max(max_depth, mut_depth);
            } else if (c == ')') {
                mut_depth--;
            }
        }
        return max_depth;
    }
};