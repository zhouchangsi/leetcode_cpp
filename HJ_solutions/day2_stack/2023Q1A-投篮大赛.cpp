/**
 * 【栈】2023Q1A-投篮大赛
 * https://og7kl7g6h8.feishu.cn/docx/Q0qIdcWeXoYmgSxffALcUSKLnHe
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  // 输入表示n个操作的数组ops
  string line;
  getline(cin, line);
  vector<string> ops;
  size_t pos = 0;
  while ((pos = line.find(' ')) != string::npos) {
    ops.push_back(line.substr(0, pos));
    line.erase(0, pos + 1);
  }
  ops.push_back(line);

  stack<int> stack;  // 初始化一个空栈

  bool isError =
      false;  // 用于标记是否出现异常的标志，初始化为false表示没有异常

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
    // 将isError修改为true，同时直接退出循环
    else {
      isError = true;
      break;
    }
  }

  // 如果出现异常，输出-1
  // 如果没有异常，输出整个栈中数字的总和
  int sum = 0;
  if (!isError) {
    while (!stack.empty()) {
      sum += stack.top();
      stack.pop();
    }
  }
  cout << (isError ? -1 : sum) << endl;

  return 0;
}
