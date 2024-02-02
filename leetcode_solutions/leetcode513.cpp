#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

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

TEST(leetcode513, solution) {
  Solution solution;
  TreeNode* root = create_tree("2,1,3");
  EXPECT_EQ(solution.findBottomLeftValue(root), 1);
  delete root;
}
