#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
  int *nums;
  int front{}, rear{}, len, sz{};

 public:
  MyCircularDeque(int k) : len(k) { nums = new int[k]; }

  bool insertFront(int value) {
    if (isFull()) return false;
    ++sz;
    front = (front - 1 + len) % len;
    nums[front] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    ++sz;
    nums[rear] = value;
    rear = (rear + 1) % len;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    --sz;
    front = (front + 1) % len;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    --sz;
    rear = (rear - 1 + len) % len;
    return true;
  }

  int getFront() {
    if (isEmpty()) return -1;
    return (nums[front]);
  }

  int getRear() {
    if (isEmpty()) return -1;
    return (nums[(rear - 1 + len) % len]);
  }

  bool isEmpty() { return sz == 0; }

  bool isFull() { return sz == len; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */