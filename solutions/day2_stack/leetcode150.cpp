/**
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * https://ahym1n4sq5.feishu.cn/docx/Udkkd4S8KoKHqsxNN4dcYjNDnfb
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if (token == "+") {
          s.push(a + b);
        } else if (token == "-") {
          s.push(a - b);
        } else if (token == "*") {
          s.push(a * b);
        } else if (token == "/") {
          s.push(a / b);
        }
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};