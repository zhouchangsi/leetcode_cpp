#include "common_headers.h"

using namespace std;

// class MyStack {
//  private:
//   queue<int> q_;
//   int top_ = 0;

//  public:
//   MyStack() {}

//   void push(int x) {
//     q_.push(x);
//     top_ = x;
//   }

//   int pop() {
//     int size = q_.size();
//     while (size > 2) {
//       q_.push(q_.front());
//       q_.pop();
//       size--;
//     }
//     top_ = q_.front();
//     q_.push(q_.front());
//     q_.pop();

//     int tmp = q_.front();
//     q_.pop();
//     return tmp;
//   }

//   int top() { return top_; }

//   bool empty() { return q_.empty(); }
// };

class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    /** Get the top element. */
    int top() {
        int r = q.front();
        return r;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

TEST(leetcode225, case1) {
  MyStack s;
  s.push(1);
  s.push(2);
  ASSERT_EQ(s.top(), 2);
  ASSERT_EQ(s.pop(), 2);
  ASSERT_FALSE(s.empty());
  ASSERT_EQ(s.top(), 1);
  ASSERT_EQ(s.pop(), 1);
  ASSERT_TRUE(s.empty());
}