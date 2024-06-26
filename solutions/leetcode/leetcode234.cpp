#include "../leetcode.h"

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return true;
    }

    // 找到前半部分链表的尾节点并反转后半部分链表
    ListNode* left_end = end_of_first_half(head);
    ListNode* right_start = reverse_list(left_end->next);

    // 判断是否回文
    ListNode* p1 = head;
    ListNode* p2 = right_start;
    bool result = true;
    while (result && p2 != nullptr) {
      if (p1->val != p2->val) {
        result = false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }

    // 还原链表并返回结果
    left_end->next = reverse_list(right_start);
    return result;
  }

  ListNode* reverse_list(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }

  ListNode* end_of_first_half(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};