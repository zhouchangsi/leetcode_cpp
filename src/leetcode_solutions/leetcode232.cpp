#include "common_headers.h"

using namespace std;

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int ret = s2.top();
    s2.pop();
    return ret;
  }

  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty() {
    if (s1.empty() && s2.empty()) {
      return true;
    }
    return false;
  }

 private:
  stack<int> s1;
  stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

TEST(leetcode232, solution) {
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  EXPECT_EQ(q.pop(), 1);
}
