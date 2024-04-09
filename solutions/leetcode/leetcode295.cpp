#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
  priority_queue<int> left;                              // max heap
  priority_queue<int, vector<int>, greater<int>> right;  // min heap

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (left.empty() || num < left.top() ) {
      left.push(num);
      if (left.size() - right.size() > 1) {
        right.push(left.top());
        left.pop();
      }
    } else {
      right.push(num);
      if (right.size() - left.size() > 1) {
        left.push(right.top());
        right.pop();
      }
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return (left.top() + right.top()) / 2.0;
    } else {
      return left.size() > right.size() ? left.top() : right.top();
    }
  }
};