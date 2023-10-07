#include "common_headers.h"
#include "tree_node.h"

using namespace std;

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int result = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      result = q.front()->val;
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
    }
    return result;
  }
};

TEST(leetcode513, case1) {
  Solution solution;
  TreeNode* root = new TreeNode("2,1,3");
  EXPECT_EQ(solution.findBottomLeftValue(root), 1);
  delete root;
}

TEST(leetcode513, case2) {
  Solution solution;
  TreeNode* root = new TreeNode("1,2,3,4,null,5,6,null,null,7");
  EXPECT_EQ(solution.findBottomLeftValue(root), 7);
  delete root;
}