#include "./leetcode/leetcode.h"
#include <cassert>

using namespace leetcode;

class Solution
{
public:
  ListNode* sortList(ListNode* head) { return sortList(head, nullptr); }

  ListNode* sortList(ListNode* head, ListNode* tail)
  {
    // 1. 快慢指针找到中点
    if (head == nullptr) {
      return head;
    }
    if (head->next == tail) {
      head->next = nullptr;
      return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != tail) {
      slow = slow->next;
      fast = fast->next;
      if (fast != tail) {
        fast = fast->next;
      }
    }
    ListNode* mid = slow;
    // 2. 递归排序
    return merge(sortList(head, mid), sortList(mid, tail));
  }

  ListNode* merge(ListNode* head1, ListNode* head2)
  {
    if (head1 == nullptr) {
      return head2;
    }
    if (head2 == nullptr) {
      return head1;
    }
    if (head1->val < head2->val) {
      head1->next = merge(head1->next, head2);
      return head1;
    }
    head2->next = merge(head1, head2->next);
    return head2;
  }
};

int
main()
{
  // case 1
  {
    auto head = create_list("4,2,1,3");
    auto expected = create_list("1,2,3,4");
    auto actual = Solution{}.sortList(head);
    assert(is_same_list(expected, actual));
  }
  // case 2
  {
    auto head = create_list("-1,5,3,4,0");
    auto expected = create_list("-1,0,3,4,5");
    auto actual = Solution{}.sortList(head);
    assert(is_same_list(expected, actual));
  }
  // case 3
  {
    auto head = create_list("");
    auto expected = create_list("");
    auto actual = Solution{}.sortList(head);
    assert(is_same_list(expected, actual));
  }

  return 0;
}