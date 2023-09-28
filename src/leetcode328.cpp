#include "common_headers.h"
#include "data_structure/list_node.hpp"

using namespace std;

class MyQueue {
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
  MyQueue solution;
  ListNode* l1 = new ListNode(7);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  l1->next->next->next = new ListNode(3);
}