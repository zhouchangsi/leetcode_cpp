// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/submissions/444748416/
// https://r07na4yqwor.feishu.cn/docx/T7hldlbjZoG6ycxpaqBcqyRrnWh
#include "../leetcode.h"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* right = head;
    ListNode* left = dummy;
    while (n--) right = right->next;

    while (right != nullptr) {
      right = right->next;
      left = left->next;
    }  // 此时right指向尾节点的下一个节点，left指向倒数第n+1个节点
    left->next = left->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
  }
};