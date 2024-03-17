/**
 * https://leetcode.cn/problems/valid-palindrome/submissions/509975819/
 * https://r07na4yqwor.feishu.cn/docx/S2P0dqQlvoMxwqxfOkicgI4NnBb
*/

#include "../leetcode/env.h"

class Solution {
public:
    bool isPalindrome(string s) {
        string _s;
        for(auto c:s) {
            if(isalnum(c)) {
                _s += tolower(c);
            }
        }
        int n = _s.size();
        int left = 0, right = n - 1;
        while(left < right) {
            if(_s[left] != _s[right]) {
                return false;
            }
            left++, right--;
        }
        return true;
    }
};