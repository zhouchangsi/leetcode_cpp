#include "common_headers.h"
#include "list_node.h"

using namespace std;

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

TEST(leetcode328, case1) {
  Solution solution;
  ListNode* l1 = new ListNode("7, 2, 4, 3");
  ListNode* result = solution.oddEvenList(l1);
  ListNode* expect = new ListNode("7,4,2,3");
  EXPECT_TRUE(result->equals(expect));
  delete result, expect;
}