#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) { return helper(head, nullptr); }
  TreeNode* helper(ListNode* head, ListNode* tail) {
    if (head == tail) {
      return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = helper(head, slow);
    root->right = helper(slow->next, tail);
    return root;
  }
};

TEST(leetcode109, solution) {
  ListNode* head = create_list("-10, -3, 0, 5, 9");
  TreeNode* expect = create_tree("0,-3,9,-10,null,5");
  TreeNode* result = Solution().sortedListToBST(head);
  EXPECT_TRUE(is_same_tree(result, expect));
}