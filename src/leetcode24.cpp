#include "common_headers.h"
#include "utils/list_node.hpp"

using namespace std;

class MyQueue {
  // 定义：输入以 head 开头的单链表，将这个单链表中的每两个元素翻转，
  // 返回翻转后的链表头结点
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {  // 递归结束条件
      return head;
    }
    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* others = head->next->next;
    // 先把前两个元素翻转
    second->next = first;
    // 利用递归定义，将剩下的链表节点两两翻转，接到后面
    first->next = swapPairs(others);
    // 现在整个链表都成功翻转了，返回新的头结点
    return second;
  }
};

TEST(leetcode24,case1) {
    MyQueue solution;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    ListNode* result = solution.swapPairs(head);

    ListNode* expect = new ListNode(2);
    expect->next = new ListNode(1);
    expect->next->next = new ListNode(4);
    expect->next->next->next = new ListNode(3);
    EXPECT_TRUE(ListTest::is_equals(result, expect));
}