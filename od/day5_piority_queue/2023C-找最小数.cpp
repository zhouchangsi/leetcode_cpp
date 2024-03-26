/**
 * 2023C-找最小数
 * https://og7kl7g6h8.feishu.cn/docx/YxcWdNjDCo0bSaxxwnhcOol0nzf
 */
#include <bits/stdc++.h>
using namespace std;
void solution(string s, int k) {
  stack<char> st;
  for (char c : s) {
    while (!st.empty() && c < st.top() && k > 0) {
      st.pop();
      k--;
    }
    st.push(c);
  }

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
  //   auto it = find_if(ans.begin(), ans.end(), [](char c) { return c != '0';
  //   }); cout << ans.substr(distance(ans.begin(), it)) << '\n';
  cout << ans << '\n';
}

int main() {
  //   solution("12345", 2);  // 123
  //   solution("10345", 2);  // 034

  string s;
  getline(cin, s);
  int k;
  cin >> k;
  solution(s, k);

  return 0;
}