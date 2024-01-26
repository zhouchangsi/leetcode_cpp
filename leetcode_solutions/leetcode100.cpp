#include "./leetcode/leetcode.h"
#include <cassert>

using namespace leetcode;

class Solution
{
public:
  bool isSameTree(TreeNode* p, TreeNode* q)
  {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int
main()
{
  auto p = leetcode::create_tree("1,2,3");
  auto q = leetcode::create_tree("1,2,3,4");
  assert(leetcode::is_same_tree(p, q));
  return 0;
}