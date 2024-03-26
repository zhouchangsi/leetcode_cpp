/**
 * 【栈】2023Q1A-投篮大赛
 * https://og7kl7g6h8.feishu.cn/docx/Q0qIdcWeXoYmgSxffALcUSKLnHe
 */
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solve(string line) {
  vector<string> ops;
  istringstream iss(line);
  string token;
  while (iss >> token) ops.push_back(token);

  stack<int> stack;

  for (const string& record : ops) {
    // 若record为数字，则直接将该数字加入栈中，注意要将字符串转为整数
    if (record != "D" && record != "C" && record != "+") {
      stack.push(stoi(record));
    }
    // 若record为'D'，且栈长度大于等于1，则在栈顶压入两倍的原栈顶值
    else if (record == "D" && stack.size() >= 1) {
      stack.push(stack.top() * 2);
    }
    // 若record为'C'，且栈长度大于等于1，则弹出栈顶元素
    else if (record == "C" && stack.size() >= 1) {
      stack.pop();
    }
    // 若record为'+'，且栈长度大于等于2，则在栈顶压入原栈顶的两个值的和
    else if (record == "+" && stack.size() >= 2) {
      int top1 = stack.top();
      stack.pop();
      int top2 = stack.top();
      stack.push(top1);
      stack.push(top1 + top2);
    }
    // 如果不满足上述的任何条件，说明出现了异常
    else {
      return -1;
    }
  }

  int sum = 0;
  while (!stack.empty()) {
    sum += stack.top();
    stack.pop();
  }
  return sum;
}

int main() {
  cout << solve("5 2 C D +") << endl;         // 30
  cout << solve("5 -2 4 C D 9 + +") << endl;  // 5
  cout << solve("1") << endl;                 // 1
  cout << solve("+") << endl;                 // -1

  // string line;
  // getline(cin, line);
  // cout << solve(line) << endl;
  return 0;
}
