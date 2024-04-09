// https://leetcode.cn/problems/reverse-nodes-in-k-group/
// https://leetcode.cn/problems/reverse-nodes-in-k-group/solutions/1992228/you-xie-cuo-liao-yi-ge-shi-pin-jiang-tou-plfs/comments/2132515
#include "leetcode.h"
using namespace std;

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tail = head;
    for (int i = 0; i < k; i++) {
      if (!tail) return head;
      tail = tail->next;
    }

    ListNode *pre = nullptr, *cur = head, *next = nullptr;
    for (int i = 0; i < k; i++) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    head->next = reverseKGroup(cur, k);
  }
};