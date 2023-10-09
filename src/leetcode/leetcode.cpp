#include "leetcode.h"

namespace leetcode {

bool is_integer(const std::string& s) {
  if (s.empty()) {
    return false;
  }
  auto it = s.begin();
  if (*it == '+' || *it == '-') {
    it++;
  }
  if (it == s.end()) {
    return false;
  }
  return std::all_of(it, s.end(), ::isdigit);
}

std::vector<std::optional<int>> parse_leetcode_list(std::string str) {
  if (str[0] == '[') {
    // cut the first '[' and last ']'
    str = str.substr(1, str.size() - 2);
  }
  str += ",";
  std::vector<std::optional<int>> nodes;
  std::string token = "";
  int i = 0;
  do {
    auto c = str[i];
    if (c != ',') {
      token += c;
      continue;
    }
    nodes.push_back(token == "null" ? std::optional<int>(std::nullopt)
                                    : std::optional<int>(std::stoi(token)));
    token = "";
  } while (i++ < str.size());
  return nodes;
}

std::vector<std::vector<int>> parse_leetcode_matrix(std::string matrix) {
  // cut the first '[' and last ']'
  matrix = matrix.substr(1, matrix.size() - 2);
  std::vector<std::vector<int>> rows;
  std::string row = "";  // e.g. "1,2,3"
  int i = 0;
  do {
    auto c = matrix[i];
    if (c == '[') {
      row = "";
      continue;
    }
    if (c != ']') {
      row += c;
      continue;
    }

    row += c;
    auto optional_nums = parse_leetcode_list(row);
    std::vector<int> nums;
    for (auto num : optional_nums) {
      nums.push_back(num.value());
    }
    rows.push_back(nums);
  } while (i++ < matrix.size());
  return rows;
}

bool is_same_list(ListNode* list1, ListNode* list2) {
  ListNode *node1 = list1, *node2 = list2;
  while (node1 != nullptr && node2 != nullptr) {
    if (node1->val != node2->val) {
      return false;
    }
    node1 = node1->next;
    node2 = node2->next;
  }
  return node1 == nullptr && node2 == nullptr;
}

ListNode* create_list(std::string str) {
  auto nums = parse_leetcode_list(str);
  ListNode* node = new ListNode();
  ListNode* head = node;
  for (auto num : nums) {
    node->val = num.value();
    node = (node->next = new ListNode());
  }
  return head;
}

TreeNode* create_tree(std::string str) {
  auto nums = parse_leetcode_list(str);
  TreeNode* root = new TreeNode(nums[0].value());
  std::queue<TreeNode*> q;
  q.push(root);
  int i = 1;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    if (i < nums.size() && nums[i].has_value()) {
      node->left = new TreeNode(nums[i].value());
      q.push(node->left);
    }
    i++;
    if (i < nums.size() && nums[i].has_value()) {
      node->right = new TreeNode(nums[i].value());
      q.push(node->right);
    }
    i++;
  }
  return root;
}

bool is_same_tree(TreeNode* root1, TreeNode* root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }
  if (root1->val != root2->val) {
    return false;
  }
  return is_same_tree(root1->left, root2->left) &&
         is_same_tree(root1->right, root2->right);
}

int tree_depth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return std::max(tree_depth(root->left), tree_depth(root->right)) + 1;
}

int tree_size(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return tree_size(root->left) + tree_size(root->right) + 1;
}
}  // namespace leetcode