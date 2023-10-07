#include "common_headers.h"
#include "tree_node.h"

using namespace std;

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
  auto expect = new TreeNode("0,-3,9,-10,null,5");
  EXPECT_TRUE(result->equals(expect));
  delete result, expect;
}
