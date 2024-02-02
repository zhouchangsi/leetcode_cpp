#include "leetcode.h"
#include <gtest/gtest.h>

using namespace std;
using namespace leetcode;

TEST(helper, is_number)
{
  EXPECT_TRUE(is_integer("123"));
  EXPECT_TRUE(is_integer("-123"));
  EXPECT_TRUE(is_integer("0"));
  EXPECT_TRUE(is_integer("0123"));
  EXPECT_TRUE(is_integer("+123"));
  EXPECT_FALSE(is_integer(""));
  EXPECT_FALSE(is_integer("abc"));
  EXPECT_FALSE(is_integer("123a"));
  EXPECT_FALSE(is_integer("123.0"));
}

TEST(helper, _parse_leetcode_string)
{
  vector<optional<int>> expected = { 1, 2, 3, nullopt, nullopt, 4, 5 };
  {
    auto nodes = parse_leetcode_list("[1,2,3,null,null,4,5]");
    EXPECT_EQ(nodes, expected);
  }
  {
    auto nodes = parse_leetcode_list("1,2,3,null,null,4,5");
    EXPECT_EQ(nodes, expected);
  }
}

TEST(helper, _parse_leetcode_matrix)
{
  auto matrix = parse_leetcode_matrix("[[2,4],[1,3],[2,4],[1,3]]");
  std::vector<std::vector<int>> expected = {
    { 2, 4 }, { 1, 3 }, { 2, 4 }, { 1, 3 }
  };
  EXPECT_EQ(matrix, expected);
}

TEST(list, apis)
{
  auto list1 = create_list("1,2,3,4,5");
  EXPECT_EQ(list1->val, 1);
  EXPECT_EQ(list1->next->val, 2);
  EXPECT_EQ(list1->next->next->val, 3);
  EXPECT_EQ(list1->next->next->next->val, 4);
  EXPECT_EQ(list1->next->next->next->next->val, 5);
  auto list2 = create_list("1,2,3,4,5");
  auto list3 = create_list("1,2,3,4,6");
  EXPECT_TRUE(is_same_list(list1, list2));
  EXPECT_FALSE(is_same_list(list1, list3));
  delete list1;
  delete list2;
  delete list3;
}

TEST(tree, apis)
{
  auto tree_1 = create_tree("1,2,3");
  EXPECT_EQ(tree_1->val, 1);
  EXPECT_EQ(tree_1->left->val, 2);
  EXPECT_EQ(tree_1->right->val, 3);
  EXPECT_EQ(tree_depth(tree_1), 2);

  auto tree_2 = create_tree("1,2,3");
  EXPECT_TRUE(is_same_tree(tree_1, tree_2));
  delete tree_1;
  delete tree_2;

  auto tree_3 = create_tree("0,-3,9,-10,null,5");
  auto tree_4 = create_tree("0,-3,9,-10,null,5");
  EXPECT_EQ(tree_depth(tree_3), 3);
  EXPECT_EQ(tree_size(tree_4), 5);
  EXPECT_TRUE(is_same_tree(tree_3, tree_4));
  delete tree_3;
  delete tree_4;
}

TEST(union_find_sets, ok)
{
  UnionFindSets ufs(10);
  EXPECT_EQ(ufs.find(1), 1);
  EXPECT_EQ(ufs.find(2), 2);
  EXPECT_EQ(ufs.find(3), 3);
  EXPECT_EQ(ufs.find(4), 4);
  EXPECT_EQ(ufs.find(5), 5);
  EXPECT_EQ(ufs.find(6), 6);
  EXPECT_EQ(ufs.find(7), 7);
  EXPECT_EQ(ufs.find(8), 8);
  EXPECT_EQ(ufs.find(9), 9);
  EXPECT_EQ(ufs.find(10), 10);
}