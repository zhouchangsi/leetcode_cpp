#pragma once
#include "./common.h"

namespace leetcode {

/**
 * @brief Leetcode's graph node named Node.
 */
class Node
{
public:
  int val;
  std::vector<Node*> neighbors;
  Node()
  {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Graph
{
public:
  std::map<int, Node*> nodes;
  /**
   * @brief Construct a new Graph object
   *
   * @param adj_list e.g. "[[2,4],[1,3],[2,4],[1,3]]"
   */
  Graph(std::string adj_list)
  {
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

};