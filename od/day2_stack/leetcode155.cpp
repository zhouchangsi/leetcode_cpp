/**
 * https://leetcode-cn.com/problems/min-stack/
 * https://ahym1n4sq5.feishu.cn/docx/NufNdNmIDosCkjxwvoQcNXUAn9c
 */
#include <bits/stdc++.h>
using namespace std;

class MinStack {
  stack<int> x_stack;
  stack<int> min_stack;

 public:
  MinStack() { min_stack.push(INT_MAX); }

  void push(int x) {
    x_stack.push(x);
    min_stack.push(min(min_stack.top(), x));
  }

  void pop() {
    x_stack.pop();
    min_stack.pop();
  }

  int top() { return x_stack.top(); }

  int getMin() { return min_stack.top(); }
};