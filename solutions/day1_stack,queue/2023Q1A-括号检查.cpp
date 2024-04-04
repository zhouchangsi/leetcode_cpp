/**
 * https://og7kl7g6h8.feishu.cn/docx/Lb02dypAmoNxu8xbBQncrBnkn0e
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int max_depth(const string& s) {
  // 若字符串长度为奇数，必定无法配对，返回0
  if (s.length() % 2 == 1) return 0;
  int ans = 0;
  int cur_depth = 0;
  stack<char> stack;
  for (char ch : s) {
    if (ch == '(' || ch == '{' || ch == '[') {
      stack.emplace(ch);
      cur_depth++;
      ans = max(ans, cur_depth);
    } else {
      if (stack.empty()) {
        return 0;
      }
      char top = stack.top();
      stack.pop();
      cur_depth--;
      if ((top == '(' && ch != ')') ||  //
          (top == '{' && ch != '}') ||  //
          (top == '[' && ch != ']')     //
      ) {
        return 0;
      }
    }
  }
  return stack.empty() ? ans : 0;
}

int main() {
  //   cout << max_depth("[]") << endl;
  //   cout << max_depth("([]{()})") << endl;
  //   cout << max_depth("(]") << endl;
  //   cout << max_depth("([)]") << endl;
  //   cout << max_depth(")(") << endl;

  string s;
  getline(cin, s);
  cout << max_depth(s) << endl;
  return 0;
}
