#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      double sum = 0;
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        sum += node->val;
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
      }
      result.push_back(sum / size);
    }
    return result;
  }
};

TEST(leetcode637, solution) {
  Solution solution;
  TreeNode* root = create_tree("3,9,20,null,null,15,7");
  vector<double> result = solution.averageOfLevels(root);
  vector<double> expected = {3, 14.5, 11};
  for (int i = 0; i < expected.size(); i++) {
    EXPECT_FLOAT_EQ(result[i], expected[i]);
  }
}