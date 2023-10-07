#pragma once

#include <sstream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  /**
   * @param str e.g. "1,2,3,4,5"
   */
  ListNode(std::string str);
  ~ListNode();
  bool equals(ListNode* node);
};
