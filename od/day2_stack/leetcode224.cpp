/**
 * https://leetcode-cn.com/problems/basic-calculator/
 * https://ahym1n4sq5.feishu.cn/docx/G1FmdZGPmouZLHxjGdjc4O7rnNh
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    stack<int> st;
    int left_sum = 0, sign = 1, right_sum = 0;
    for (auto ch : s) {
      if (ch == ' ') continue;
      if (isdigit(ch)) {
        right_sum = right_sum * 10 + (ch - '0');
      } else {
        left_sum += sign * right_sum;
        right_sum = 0;
        if (ch == '+') {
          sign = 1;
        } else if (ch == '-') {
          sign = -1;
        } else if (ch == '(') {
          st.push(left_sum);
          st.push(sign);
          left_sum = 0;
          sign = 1;
        } else if (ch == ')') {
          left_sum = st.top() * left_sum;
          st.pop();
          left_sum += st.top();
          st.pop();
        }
      }
    }
    return left_sum + sign * right_sum;
  }
};

int main() {
  int res = Solution().calculate("1-(     -2)");
  cout << res << endl;
  return 0;
}