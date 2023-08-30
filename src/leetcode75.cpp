#include "common_headers.h"

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();

    // i is the last index of 0
    int i = -1;
    for (int j = 0; j < n; ++j) {
      // 0 put to the left
      if (nums[j] == 0) {
        i++;
        swap(nums[i], nums[j]);
      }
    }

    for (int j = i + 1; j < n; ++j) {
      // 1 put to after 0
      if (nums[j] == 1) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
  }
};

TEST(leetcode75, case1) {
  Solution s;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  s.sortColors(nums);
  EXPECT_EQ(nums, vector<int>({0, 0, 1, 1, 2, 2}));
}