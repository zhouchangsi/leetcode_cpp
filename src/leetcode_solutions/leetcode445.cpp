#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 把链表元素转入栈中
    stack<int> stk1, stk2;
    while (l1 != nullptr) {
      stk1.push(l1->val);
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      stk2.push(l2->val);
      l2 = l2->next;
    }

    // 接下来基本上是复用我在第 2 题的代码逻辑
    // 注意新节点要直接插入到 dummy 后面

    // 虚拟头结点（构建新链表时的常用技巧）
    ListNode* dummy = new ListNode(-1);

    // 记录进位
    int carry = 0;
    // 开始执行加法，两条链表走完且没有进位时才能结束循环
    while (!stk1.empty() || !stk2.empty() || carry > 0) {
      // 先加上上次的进位
      int val = carry;
      if (!stk1.empty()) {
        val += stk1.top();
        stk1.pop();
      }
      if (!stk2.empty()) {
        val += stk2.top();
        stk2.pop();
      }
      // 处理进位情况
      carry = val / 10;
      val = val % 10;
      // 构建新节点，直接接在 dummy 后面
      ListNode* newNode = new ListNode(val);
      newNode->next = dummy->next;
      dummy->next = newNode;
    }
    // 返回结果链表的头结点（去除虚拟头结点）
    ListNode* result = dummy->next;
    delete dummy;
    dummy = nullptr;
    return result;
  }
};

TEST(leetcode445, solution) {
  Solution my_queue;
  ListNode* l1 = create_list("7, 2, 4, 3");
  ListNode* l2 = create_list("5, 6, 4");
  ListNode* result = my_queue.addTwoNumbers(l1, l2);
  ListNode* expect = create_list("7,8,0,7");
  EXPECT_TRUE(is_same_list(result, expect));
}