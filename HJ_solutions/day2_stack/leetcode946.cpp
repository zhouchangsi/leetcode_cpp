/**
 * https://leetcode-cn.com/problems/validate-stack-sequences/
 * https://ahym1n4sq5.feishu.cn/docx/FpqLdlh8ao89xWxV0LPcgYVenyK
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    // 利用栈来模拟入栈和出栈操作
    stack<int> s;

    // index 表示 popped 数组中元素的下标
    // 比如 popped 是 [4,5,3,2,1]
    // 那么第 0 个下标元素是 4 这个数字
    // 先去判断这个数字能否正常的出栈
    int index = 0;

    // 遍历 pushed 数组中的每个元素
    for (int i = 0; i < pushed.size(); i++) {
      // 在遍历 pushed 数组时，把当前遍历的元素加入到栈中
      s.push(pushed[i]);

      // 加入完之后，不断的执行以下的判断
      // 1、栈中是否有元素
      // 2、栈顶元素是否和 popped 当前下标的元素相同
      // 如果同时满足这两个条件
      // 说明这个元素可以满足要求，即可以在最初空栈上进行推入 push 和弹出 pop
      // 操作
      while (!s.empty() && popped[index] == s.top()) {
        // 那么就把栈顶元素弹出
        s.pop();

        // 同时 index++，观察 popped 下一个元素
        index++;
      }
    }

    // 遍历完 pushed 数组中的每个元素之后，如果发现栈不为空
    if (!s.empty()) {
      // 那么说明出栈序列不合法，返回 false
      return false;
    }

    // 否则返回 true
    return true;
  }
};