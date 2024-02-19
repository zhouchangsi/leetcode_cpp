#include "./leetcode/env.h"

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string curStr;
        int curNum = 0;
        for (char c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + c - '0';
            } else if (isalpha(c)) {
                curStr.push_back(c);
            } else if (c == '[') {
                numStack.push(curNum);
                strStack.push(curStr);
                curNum = 0;
                curStr.clear();
            } else if (c == ']') {
                int k = numStack.top();
                numStack.pop();
                string t = curStr;
                for (int i = 1; i < k; i++) {
                    curStr += t;
                }
                curStr = strStack.top() + curStr;
                strStack.pop();
            }
        }
        return curStr;
    }
};