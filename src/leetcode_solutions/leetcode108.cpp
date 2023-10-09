#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
  TreeNode* helper(vector<int>& nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }

    // 总是选择中间位置左边的数字作为根节点
    int mid = (left + right) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
  }
};

TEST(leetcode108, solution) {
  Solution solution;
  vector<int> nums = {-10, -3, 0, 5, 9};
  auto result = solution.sortedArrayToBST(nums);
  auto expect1 = create_tree("0,-3,9,-10,null,5");
  auto expect2 = create_tree("0,-10,5,null,-3,null,9");

  EXPECT_TRUE(leetcode::is_same_tree(result, expect1) ||
              leetcode::is_same_tree(result, expect2));
  delete result, expect1, expect2;
}
