#include "list_node.h"
#include "helper.h"

ListNode::ListNode(std::string str) {
  auto nums = leetcode::parse_leetcode_list(str);
  ListNode* node = this;
  for (auto num : nums) {
    node->val = num.value();
    node = (node->next = new ListNode());
  }
}

ListNode::~ListNode() {
  delete next;
}

bool ListNode::equals(ListNode* node) {
  ListNode* _node = this;
  while (_node != nullptr && node != nullptr) {
    if (_node->val != node->val) {
      return false;
    }
    _node = _node->next;
    node = node->next;
  }
  bool result = _node == nullptr && node == nullptr;
  return result;
}