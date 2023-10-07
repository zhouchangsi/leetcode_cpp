#include <map>
#include <set>
#include <string>
#include <vector>
#include "leetcode.h"

using std::map;
using std::set;
using std::string;
using std::vector;

namespace leetcode {
class Node;
class Graph;
}  // namespace leetcode

// [[2,4],[1,3],[2,4],[1,3]]
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }

  bool has_same_neighbors(Node* another) {
    if (neighbors.size() != another->neighbors.size()) {
      return false;
    }
    for (auto neighbor : neighbors) {
      if (!another->has_neighbor(neighbor->val)) {
        return false;
      }
    }
    return true;
  }

  bool has_neighbor(int val) {
    for (auto neighbor : neighbors) {
      if (neighbor->val == val) {
        return true;
      }
    }
  }

  Node* clone(set<Node*>&& visited = set<Node*>()) {
    auto new_node = new Node(val);
    for (auto neighbor : neighbors) {
      new_node->neighbors.push_back(neighbor->clone(std::move(visited)));
    }
    return new_node;
  }

  static Node* clone(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    auto new_node = new Node(node->val);
    for (auto neighbor : node->neighbors) {
      new_node->neighbors.push_back(clone(neighbor));
    }
    return new_node;
  }
};

class Graph {
 public:
  map<int, Node*> nodes;
  /**
   * @brief Construct a new Graph object
   *
   * @param adj_list e.g. "[[2,4],[1,3],[2,4],[1,3]]"
   */
  Graph(string adj_list) {
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

  bool equals(Graph& another) {
    if (nodes.size() != another.nodes.size()) {
      return false;
    }
    for (auto& [key, node] : nodes) {
      if (node->val != another.nodes[key]->val) {
        return false;
      }
      if (!node->has_same_neighbors(another.nodes[key])) {
        return false;
      }
    }
    return true;
  }
};
