#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int base = INT_MIN;
    int count = 0;
    int maxCount = 0;
    traverse(root, base, count, maxCount, ans);
    return ans;
  }
  void traverse(TreeNode* root,
                int& base,
                int& count,
                int& maxCount,
                vector<int>& ans) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left, base, count, maxCount, ans);
    if (root->val == base) {
      count++;
    } else {
      base = root->val;
      count = 1;
    }
    if (count == maxCount) {
      ans.push_back(base);
    } else if (count > maxCount) {
      ans.clear();
      ans.push_back(base);
      maxCount = count;
    }
    traverse(root->right, base, count, maxCount, ans);
  }
};

TEST(leetcode501, solution) {
  TreeNode* root = create_tree("1,null,2,2");
  vector<int> expect = {2};
  EXPECT_EQ(Solution().findMode(root), expect);
  delete root;
}