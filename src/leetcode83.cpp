#include "common_headers.h"
#include "data_structure/list_node.hpp"

using namespace std;

class MyQueue {
 public:
  ListNode* deleteDuplicates(ListNode* head) {  // 删除链表中重复的元素
    if (head == nullptr)
      return nullptr;  // 如果链表为空，直接返回NULL
    ListNode *slow = head, *fast = head;  // 定义快慢指针，初始都指向头结点
    while (fast != nullptr) {  // 只要快指针没有遍历完整个链表
      if (fast->val != slow->val) {  // 快慢指针值不同
        slow->next = fast;           // 慢指针连接新节点
        slow = slow->next;           // 慢指针向后移动一位
      }
      fast = fast->next;  // 快指针向后移动一位
    }
    slow->next = nullptr;  // 断开与后面重复元素的连接
    return head;           // 返回头结点
  }
};

TEST(leetcode83, case1) {
  MyQueue solution;
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  head->next = node1;
  node1->next = node2;
  ListNode* result = solution.deleteDuplicates(head);

  ListNode* expect = new ListNode(1);
  expect->next = new ListNode(2);
  EXPECT_TRUE(ListTest::is_equals(result, expect));
}
