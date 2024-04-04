#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string smallestSubsequence(string s) {
    unordered_map<char, int> last_occurrence;
    for (int i = 0; i < s.size(); i++) {
      last_occurrence[s[i]] = i;
    }

    stack<char> st;
    unordered_set<char> in_stack;
    for (int i = 0; i < s.size(); i++) {
      if (in_stack.count(s[i])) continue;

      while (!st.empty()                       // 栈非空
             && st.top() > s[i]                // 保证字典序
             && last_occurrence[st.top()] > i  // 之后还有这个字符，可以pop
      ) {
        in_stack.erase(st.top());
        st.pop();
      }

      st.push(s[i]);
      in_stack.insert(s[i]);
    }

    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};