#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }

    ListNode *odd = head, *even = head->next, *even_head = even;
    while (even != nullptr && even->next != nullptr) {
      odd->next = odd->next->next;
      odd = odd->next;
      even->next = even->next->next;
      even = even->next;
    }
    odd->next = even_head;
    return head;
  }
};

TEST(leetcode328, solution) {
  Solution solution;
  ListNode* l1 = create_list("7, 2, 4, 3");
  ListNode* result = solution.oddEvenList(l1);
  ListNode* expect = create_list("7,4,2,3");
  EXPECT_TRUE(is_same_list(result, expect));
  delete result, expect;
}