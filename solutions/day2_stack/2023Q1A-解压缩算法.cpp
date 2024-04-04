/**
 * 【栈】2023Q1A-解压缩算法
 * https://og7kl7g6h8.feishu.cn/docx/SvQZdrl9foGjzixARwNcvgLCnOg
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string solve(string line) {
  stack<string> stack;
  int num = 0;

  for (size_t i = 0; i < line.length(); ++i) {
    char ch = line[i];

    if (isdigit(ch)) {
      // 读取数字
      num = num * 10 + (ch - '0');
      // 如果下一个字符不是数字，说明数字读取完毕, 进行解压缩
      if (i == line.length() - 1 || !isdigit(line[i + 1])) {
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
    }
    // 如果是左括号或字母，直接入栈
    else if (ch == '{' || isalpha(ch)) {
      stack.push(string(1, ch));
    }
    // 如果是右括号，将括号内的字符串入栈
    else if (ch == '}') {
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

  return result;
}

int main() {
  // cout << solve("A3") << endl;
  // cout << solve("{A3B1{C}3}3") << endl;
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
