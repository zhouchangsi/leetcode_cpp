#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    int x = 0;
    for (auto num : nums) {
      x ^= num;
    }
    // 防止溢出
    int tmp = (x == INT_MIN ? x : x & (-x));

    int a = 0, b = 0;

    for (auto num : nums) {
      if (num & tmp) {
        a ^= num;
      } else {
        b ^= num;
      }
    }
    return {a, b};
  }
};

TEST(leetcode260, solution) {
  Solution s;
  vector<int> nums = {1, 2, 1, 3, 2, 5};
  EXPECT_EQ(s.singleNumber(nums), vector<int>({3, 5}));
}