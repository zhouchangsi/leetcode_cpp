#include "common_headers.h"
#include "utils/list_node.hpp"

using namespace std;

class MyQueue {
 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
      n++;
      temp = temp->next;
    }
    int quotient = n / k, remainder = n % k;

    vector<ListNode*> parts(k, nullptr);
    ListNode* curr = head;
    for (int i = 0; i < k && curr != nullptr; i++) {
      parts[i] = curr;
      int partSize = quotient + (i < remainder ? 1 : 0);
      for (int j = 1; j < partSize; j++) {
        curr = curr->next;
      }
      ListNode* next = curr->next;
      curr->next = nullptr;
      curr = next;
    }
    return parts;
  }
};

TEST(leetcode725, case1) {
  MyQueue solution;
  ListNode* l1 = new ListNode(7);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  l1->next->next->next = new ListNode(3);

  vector<ListNode*> result = solution.splitListToParts(l1, 2);
  vector<ListNode*> expected = {
      new ListNode(7), new ListNode(2, new ListNode(4, new ListNode(3)))};
}