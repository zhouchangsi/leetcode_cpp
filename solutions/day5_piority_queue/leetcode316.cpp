/**
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 * https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/description/
 * https://leetcode.cn/problems/remove-duplicate-letters/solutions/417758/you-qian-ru-shen-dan-diao-zhan-si-lu-qu-chu-zhong-/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    array<int, 26> last;
    for (int i = 0; i < s.size(); i++) {
      last[s[i] - 'a'] = i;
    }
    stack<char> st;
    array<bool, 26> seen = {false};
    for (int i = 0; i < s.size(); i++) {
      const char& ch = s[i];
      if (seen[ch - 'a']) continue;

      while (!st.empty() &&            // 栈非空
             st.top() > ch &&          // 保证字典序
             last[st.top() - 'a'] > i  // 之后还有这个字符，可以pop
      ) {
        seen[st.top() - 'a'] = false;
        st.pop();
      }

      st.push(ch);
      seen[ch - 'a'] = true;
    }

    string ans;
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }
    return ans;
  }
};