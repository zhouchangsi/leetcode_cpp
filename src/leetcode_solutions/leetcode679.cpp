#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;


class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> count;
    unordered_map<int, int> first;
    unordered_map<int, int> last;
    int max_count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (count.find(num) == count.end()) {
        count[num] = 1;
        first[num] = i;
        last[num] = i;
      } else {
        count[num]++;
        last[num] = i;
      }
      max_count = max(max_count, count[num]);
    }

    int answer = nums.size();
    for (auto& p : count) {
      if (p.second == max_count) {
        answer = min(answer, last[p.first] - first[p.first] + 1);
      }
    }
    return answer;
  }
};

TEST(leetcode679, solution) {
  Solution s;
  vector<int> nums = {1, 2, 2, 3, 1};
  EXPECT_EQ(s.findShortestSubArray(nums), 2);
}

TEST(leetcode679, case2) {
  Solution s;
  vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
  EXPECT_EQ(s.findShortestSubArray(nums), 6);
}