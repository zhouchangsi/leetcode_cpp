#include "common_headers.h"
#include "list_node.h"

using namespace std;

class Solution {
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
  Solution solution;
  ListNode* list = new ListNode("1,2,3");
  vector<ListNode*> result = solution.splitListToParts(list, 2);
  vector<ListNode*> expected = {
      new ListNode(7), new ListNode(2, new ListNode(4, new ListNode(3)))};
  EXPECT_EQ(result, expected);
  delete list;
  for (auto node : result) {
    delete node;
  }
}