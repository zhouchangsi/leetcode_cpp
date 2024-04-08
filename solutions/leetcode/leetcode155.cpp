// https://leetcode.cn/problems/min-stack/description/
// https://r07na4yqwor.feishu.cn/docx/V9pgd90Nfoi3dsx5LJJcqFc5nSb
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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */