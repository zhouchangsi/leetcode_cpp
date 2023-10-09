#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;  // value -> index
    for (int i = 0; i < nums.size(); ++i) {
      int v = nums[i];
      if (m.find(target - v) != m.end()) {
        return vector<int>({m[target - v], i});
      }
      m[v] = i;
    }
    return vector<int>();
  }
};

TEST(leetcode1, solution) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expect = {0, 1};
  EXPECT_EQ(Solution().twoSum(nums, target), expect);
}