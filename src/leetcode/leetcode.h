#ifndef LEETCODE_LEETCODE_H_
#define LEETCODE_LEETCODE_H_

#include <algorithm>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {
/**
 * @brief Check if a string is a integer
 * e.g. "123", "-123", "0", "0123", "+123"
 * @return true
 * @return false
 */
extern bool is_integer(const std::string& s);

/**
 * @brief Parse a string to a vector of optional integers.
 *
 * @param str e.g. "[1,2,3,null,null,4,5]" or "1,2,3,null,null,4,5"
 * @return std::vector<std::optional<int>>
 */
std::vector<std::optional<int>> parse_leetcode_list(std::string str);

/**
 * @brief Parse a string to a matrix.
 *
 * @param matrix e.g. "[[1,2,3],[4,5,6],[7,8,9]]"
 * @return vector<vector<int>>
 */
std::vector<std::vector<int>> parse_leetcode_matrix(std::string matrix);

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  ~ListNode() { delete next; }
};

/**
 * @brief compare two lists
 *
 * @param list1
 * @param list2
 * @return true
 * @return false
 */
bool is_same_list(ListNode* list1, ListNode* list2);

/**
 * @brief create a list from a string
 * @param str e.g. "1,2,3,4,5", "[1,2,3,4,5]"
 */
ListNode* create_list(std::string str);

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}

  ~TreeNode() {
    delete left;
    delete right;
  }
};

/**
 * @brief Create a tree object
 *
 * @param str level order traversal string, e.g. "[1,2,3,null,null,4,5]",
 * "1,2,3,null,null,4,5"
 * @return TreeNode*
 */
TreeNode* create_tree(std::string str);

bool is_same_tree(TreeNode* root1, TreeNode* root2);

int tree_depth(TreeNode* root);
int tree_size(TreeNode* root);

class UnionFindSets {
 public:
  std::vector<int> parent;
  UnionFindSets(int n) {
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
  }
  int find(int i) {
    if (parent[i] == i) {
      return i;
    }
    return parent[i] =
               find(parent[i]);  // assign parent[i] for path compression
  }
  void merge(int i, int j) {
    int parent_i = find(i);
    int parent_j = find(j);
    if (parent_i != parent_j) {
      parent[parent_i] = parent_j;
    }
  }
};

/**
 * @brief Leetcode's graph node named Node.
 */
class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Graph {
 public:
  std::map<int, Node*> nodes;
  /**
   * @brief Construct a new Graph object
   *
   * @param adj_list e.g. "[[2,4],[1,3],[2,4],[1,3]]"
   */
  Graph(std::string adj_list) {
    auto edges = leetcode::parse_leetcode_matrix(adj_list);
    for (int i = 0; i < edges.size(); i++) {
      nodes[i + 1]->val = i + 1;
    }
    for (int i = 0; i < edges.size(); i++) {
      for (int j = 0; j < edges[i].size(); j++) {
        auto neighbor = nodes[edges[i][j]];
        nodes[i + 1]->neighbors.push_back(neighbor);
      }
    }
  }
};

};  // namespace leetcode

#endif  // LEETCODE_LEETCODE_H_