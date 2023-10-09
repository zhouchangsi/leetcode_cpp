#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int answer = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int j = i;
      int count = 0;
      while (nums[j] >= 0) {
        int next = nums[j];
        nums[j] = -1;
        j = next;
        ++count;
      }
      answer = max(answer, count);
    }
    return answer;
  }
};

TEST(leetcode565, solution) {
  Solution s;
  vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
  EXPECT_EQ(s.arrayNesting(nums), 4);
}