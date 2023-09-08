#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListTest {
 public:
  static bool is_equals(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val != l2->val) {
        return false;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
  }

  static ListNode* from(std::vector<int> arr) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < arr.size(); ++i) {
      ListNode* node = new ListNode(arr[i]);
      if (head == nullptr) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }
    return head;
  }
};