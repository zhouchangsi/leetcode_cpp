#include "common_headers.h"

using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_len = 0;
    int cur_len = 0;
    for (auto i : nums) {
      if (i == 1) {
        cur_len++;
      } else {
        max_len = max(max_len, cur_len);
        cur_len = 0;
      }
    }
    max_len = max(max_len, cur_len);
    return max_len;
  }
};

TEST(leetcode485, case1) {
  Solution s;
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  EXPECT_EQ(s.findMaxConsecutiveOnes(nums), 3);
}