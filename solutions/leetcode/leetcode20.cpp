#include "leetcode.h"

/**
 * LC20. 有效的括号
 * https://ahym1n4sq5.feishu.cn/docx/C2RRdykrSoIiV1xGyyDcBV2WnM1
 */
class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.empty()) return false;
        if (c == ')' && st.top() != '(') return false;
        if (c == ']' && st.top() != '[') return false;
        if (c == '}' && st.top() != '{') return false;
        st.pop();
      }
    }
    return st.empty();
  }
};
