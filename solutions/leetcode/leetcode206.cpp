#include "./leetcode.h"

// leetcode206: 反转链表
// https://leetcode-cn.com/problems/reverse-linked-list/
// https://r07na4yqwor.feishu.cn/docx/AuCsdu4NNoMX7LxOaQ1clwSmnpg
// 思路：迭代
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* next = cur->next;
      cur->next = prev;

      prev = cur;
      cur = next;
    }
    return prev;
  }
};

// 思路：递归
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return new_head;
  }
};