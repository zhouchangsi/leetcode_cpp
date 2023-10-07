#include <gtest/gtest.h>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

// using std::cout;
// using std::endl;
// using std::optional;
// using std::stoi;
// using std::string;
// using std::vector;

using namespace std;

/**
 * @brief Parse a string to a vector of optional integers.
 *
 * @param str e.g. "[1,2,3,null,null,4,5]" or "1,2,3,null,null,4,5"
 * @return std::vector<std::optional<int>>
 */
vector<optional<int>> parse_leetcode_list(string str) {
  assert(str.size() > 0);
  if (str[0] == '[') {
    str = str.substr(1, str.size() - 2);
  }
  vector<optional<int>> nodes;
  string token = "";
  int i = 0;
  do {
    auto c = str[i];
    if (c != ',' && i != str.size() - 1) {
      token += c;
      continue;
    }
    if (i == str.size() - 1) {
      token += c;
    }
    nodes.push_back(token == "null" ? optional<int>(nullopt)
                                    : optional<int>(stoi(token)));
    token = "";
  } while (i++ < str.size());

  return nodes;
}

TEST(helper, parse_leetcode_string) {
  {
    auto nodes = parse_leetcode_list("[1,2,3,null,null,4,5]");
    EXPECT_EQ(nodes.size(), 7);
    EXPECT_EQ(nodes[0].value(), 1);
    EXPECT_EQ(nodes[1].value(), 2);
    EXPECT_EQ(nodes[2].value(), 3);
    EXPECT_EQ(nodes[3], std::nullopt);
    EXPECT_EQ(nodes[4], std::nullopt);
    EXPECT_EQ(nodes[5].value(), 4);
    EXPECT_EQ(nodes[6].value(), 5);
  }

  {
    auto nodes = parse_leetcode_list("1,2,3,null,null,4,5");
    EXPECT_EQ(nodes.size(), 7);
    EXPECT_EQ(nodes[0].value(), 1);
    EXPECT_EQ(nodes[1].value(), 2);
    EXPECT_EQ(nodes[2].value(), 3);
    EXPECT_EQ(nodes[3], std::nullopt);
    EXPECT_EQ(nodes[4], std::nullopt);
    EXPECT_EQ(nodes[5].value(), 4);
    EXPECT_EQ(nodes[6].value(), 5);
  }
}
