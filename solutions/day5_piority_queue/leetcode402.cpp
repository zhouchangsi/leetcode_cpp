/**
 * https://leetcode.cn/problems/remove-k-digits/description/
 * https://leetcode.cn/problems/remove-k-digits/solutions/484940/yi-diao-kwei-shu-zi-by-leetcode-solution/
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    for (int i = 0; i < num.size(); i++) {
      while (!st.empty()           // 栈不为空
             && st.top() > num[i]  // 栈顶元素大于当前元素
             && k > 0              // 可删除次数
      ) {
        st.pop();
        k--;
      }
      st.push(num[i]);
    }
    // 如果 k > 0，说明还有删除次数，从栈顶删除
    while (k > 0) {
      st.pop();
      k--;
    }
    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans[0] == '0') {
      ans.erase(ans.begin());
    }
    return ans;
  }
};