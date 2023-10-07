#include "common_headers.h"

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

TEST(leetcode155, case1) {
  MinStack obj;
  obj.push(-2);
  obj.push(0);
  obj.push(-3);
  ASSERT_EQ(obj.getMin(), -3);
  obj.pop();
  ASSERT_EQ(obj.top(), 0);
  ASSERT_EQ(obj.getMin(), -2);
}