#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto i : nums) {
      if (s.find(i) != s.end()) {
        return true;
      }
      s.insert(i);
    }
    return false;
  }
};

TEST(leetcode217, solution) {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  EXPECT_EQ(s.containsDuplicate(nums), true);
}