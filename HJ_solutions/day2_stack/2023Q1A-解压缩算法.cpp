/**
 * 【栈】2023Q1A-解压缩算法
 * https://og7kl7g6h8.feishu.cn/docx/SvQZdrl9foGjzixARwNcvgLCnOg
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;

  stack<string> stack;
  int num = 0;

  for (size_t i = 0; i < s.length(); ++i) {
    char ch = s[i];

    if (isdigit(ch)) {
      num = num * 10 + (ch - '0');
      if (i == s.length() - 1 || !isdigit(s[i + 1])) {
        int repeat = num;
        num = 0;
        string top = stack.top();
        stack.pop();
        string repeated;
        while (repeat-- > 0) {
          repeated += top;
        }
        stack.push(repeated);
      }
    } else if (ch == '{' || isalpha(ch)) {
      stack.push(string(1, ch));
    } else if (ch == '}') {
      string str_in_bracket;
      while (stack.top() != "{") {
        str_in_bracket = stack.top() + str_in_bracket;
        stack.pop();
      }
      stack.pop();
      stack.push(str_in_bracket);
    }
  }

  string result;
  while (!stack.empty()) {
    result = stack.top() + result;
    stack.pop();
  }

  cout << result << endl;

  return 0;
}
