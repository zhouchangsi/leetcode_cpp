#include "list_node.h"

ListNode::ListNode(std::string str) {
  std::stringstream ss(str);
  std::string token;
  getline(ss, token, ',');
  val = std::stoi(token);
  ListNode* node = this;
  while (getline(ss, token, ',')) {
    node->next = new ListNode(std::stoi(token));
    node = node->next;
  }
}

ListNode::~ListNode() {
  if (next != nullptr) {
    delete next;
  }
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