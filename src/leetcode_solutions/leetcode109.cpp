#include "common_headers.h"
#include "list_node.h"
#include "tree_node.h"

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
  ListNode* head = new ListNode("-10, -3, 0, 5, 9");
  TreeNode* expect = new TreeNode("0,-3,9,-10,null,5");
  TreeNode* result = Solution().sortedListToBST(head);
  EXPECT_TRUE(result->equals(expect));
  delete result, expect;
}