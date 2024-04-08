// https://leetcode.cn/problems/middle-of-the-linked-list/
// https://r07na4yqwor.feishu.cn/docx/Nxn6d4eGnoYeZZxFZWqcjoTVnff
#include "../leetcode.h"

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next;
      fast = fast->next;
    }
    return slow;
  }
};