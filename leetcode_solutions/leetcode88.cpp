#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1, p2 = n - 1, p_of_final_answer = m + n - 1;
    while (p1 >= 0 && p2 >= 0) {
      if (nums1[p1] > nums2[p2]) {
        nums1[p_of_final_answer--] = nums1[p1--];
      } else {
        nums1[p_of_final_answer--] = nums2[p2--];
      }
    }
    while (p2 >= 0) {
      nums1[p_of_final_answer--] = nums2[p2--];
    }
  }
};

TEST(leetcode88, solution) {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  vector<int> expected = {1, 2, 2, 3, 5, 6};
  Solution().merge(nums1, 3, nums2, 3);
  EXPECT_EQ(nums1, expected);
}