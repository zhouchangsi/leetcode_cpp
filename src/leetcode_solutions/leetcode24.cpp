#include "common_headers.h"
#include "list_node.h"

using namespace std;

class Solution {
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

TEST(leetcode24, case1) {
  Solution solution;
  auto head = new ListNode("1,2,3,4");
  auto result = solution.swapPairs(head);
  auto expect = new ListNode("2,1,4,3");
  EXPECT_TRUE(result->equals(expect));
  delete result, expect;
}