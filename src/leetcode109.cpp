#include "common_headers.h"
#include "data_structure/list_node.hpp"
#include "data_structure/tree_node.hpp"

using namespace std;

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
  ListNode* head = ListTest::from({-10, -3, 0, 5, 9});
  TreeNode* ans = TreeTest::from("0,-3,9,-10,null,5");
  EXPECT_TRUE(TreeTest::is_equals(Solution().sortedListToBST(head), ans));
}