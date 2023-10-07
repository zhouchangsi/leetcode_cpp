#include "helper.h"
#include <gtest/gtest.h>
using namespace std;

TEST(helper, parse_leetcode_string) {
  vector<optional<int>> expected = {1, 2, 3, nullopt, nullopt, 4, 5};
  {
    auto nodes = leetcode::parse_leetcode_list("[1,2,3,null,null,4,5]");
    EXPECT_EQ(nodes, expected);
  }
  {
    auto nodes = leetcode::parse_leetcode_list("1,2,3,null,null,4,5");
    EXPECT_EQ(nodes, expected);
  }
}

TEST(helper, parse_leetcode_matrix) {
  auto matrix = leetcode::parse_leetcode_matrix("[[2,4],[1,3],[2,4],[1,3]]");
  std::vector<std::vector<int>> expected = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
  EXPECT_EQ(matrix, expected);
}
