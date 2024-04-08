#include "./leetcode.h"
#include <cassert>

using namespace leetcode;

class Solution
{
public:
  // 总体就是判断当前节点引导的子树是不是满二叉，是的话可以直接返回子树结点数，不是的话就往下遍历。由于完全二叉树的性质，左右子树中最多只有一个子树不是满二叉。所以总体的时间复杂度仍然是logn
  // ^ 2。
  int countNodes(TreeNode* root)
  {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

int
main()
{
  // case 1
  {
    auto root = create_tree("[1,2,3,4,5,6]");
    auto ans = Solution().countNodes(root);
    assert(ans == 6);
  }
  // case 2
  {
    auto root = create_tree("[1,2,3,4,5,6,7]");
    auto ans = Solution().countNodes(root);
    assert(ans == 7);
  }
  // case 3
  {
    auto root = create_tree("[1,2,3,4,5,6,7,8,9,10,11,12,13,14]");
    auto ans = Solution().countNodes(root);
    assert(ans == 14);
  }
  return 0;
}