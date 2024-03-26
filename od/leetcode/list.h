#pragma once
#include "./common.h"

namespace leetcode {

struct ListNode
{
  int val;
  ListNode* next;
  ListNode()
    : val(0)
    , next(nullptr)
  {
  }
  ListNode(int x)
    : val(x)
    , next(nullptr)
  {
  }
  ListNode(int x, ListNode* next)
    : val(x)
    , next(next)
  {
  }
  ~ListNode() { delete next; }
};

/**
 * @brief compare two lists
 *
 * @param list1
 * @param list2
 * @return true
 * @return false
 */
inline bool
is_same_list(ListNode* list1, ListNode* list2)
{
  ListNode *node1 = list1, *node2 = list2;
  while (node1 != nullptr && node2 != nullptr) {
    if (node1->val != node2->val) {
      return false;
    }
    node1 = node1->next;
    node2 = node2->next;
  }
  return node1 == nullptr && node2 == nullptr;
}

/**
 * @brief create a list from a string
 * @param str e.g. "1,2,3,4,5", "[1,2,3,4,5]"
 */
inline ListNode*
create_list(std::string str)
{
  auto nums = parse_leetcode_list<int>(str);
  if (nums.empty()) {
    return nullptr;
  }
  ListNode* node = new ListNode();
  ListNode* head = node;
  for (auto num : nums) {
    node->val = num.value();
    node = (node->next = new ListNode());
  }
  return head;
}

};