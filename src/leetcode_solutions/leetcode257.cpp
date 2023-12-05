#include "common_headers.h"

using namespace std;

class Solution
{
public:
  void construct_paths(TreeNode* root, string path, vector<string>& paths)
  {
    if (root == nullptr) {
      return;
    }

    path += to_string(root->val);

    if (root->left == nullptr && root->right == nullptr) { // 当前节点是叶子节点
      paths.push_back(path); // 把路径加入到答案中
      return;
    }

    path += "->"; // 当前节点不是叶子节点，继续递归遍历
    construct_paths(root->left, path, paths);
    construct_paths(root->right, path, paths);
  }

  vector<string> binaryTreePaths(TreeNode* root)
  {
    vector<string> paths;
    construct_paths(root, "", paths);
    return paths;
  }
};

TEST(leetcode257, solution)
{
  Solution s;
  TreeNode* root = create_tree("1,2,3,null,5");
  vector<string> ans = s.binaryTreePaths(root);
  vector<string> expected = { "1->2->5", "1->3" };
  EXPECT_EQ(ans, expected);
}