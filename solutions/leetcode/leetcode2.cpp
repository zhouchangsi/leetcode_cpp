// https://leetcode-cn.com/problems/add-two-numbers/
// https://r07na4yqwor.feishu.cn/docx/Tuhnd8295owWB0xD58NczF71nmr
#include "../leetcode.h"

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    int carry = 0;
    while (l1 || l2) {
      int x = l1 ? l1->val : 0;
      int y = l2 ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      cur->next = new ListNode(sum % 10);
      cur = cur->next;
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
    }
    if (carry) {
      cur->next = new ListNode(carry);
    }
    return dummy->next;
  }
};