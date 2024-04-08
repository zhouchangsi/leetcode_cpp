/**
 * https://og7kl7g6h8.feishu.cn/docx/Rz1rdiUkFoPsoPx5mbAc15JInEb
 */
#include <bits/stdc++.h>
using namespace std;

void solution(string s) {
  unordered_map<char, int> count;
  for (auto c : s) count[c]++;

  stack<char> st;
  unordered_set<char> in_stack;

  for (char c : s) {
    if (in_stack.count(c)) {
      count[c]--;
    } else {
      while (!st.empty()             // 栈非空
             && c > st.top()         // 保证大小
             && count[st.top()] > 1  // 之前还有这个字符，可以pop
      ) {
        count[st.top()]--;
        in_stack.erase(st.top());
        st.pop();
      }

      st.push(c);
      in_stack.insert(c);
    }
  }

  string ans;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}

int main() {
  string s = "42234";
  //   string s = "12341";
  getline(cin, s);
  solution(s);

  return 0;
}
