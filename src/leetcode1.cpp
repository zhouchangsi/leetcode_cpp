#include "common_headers.h"

using namespace std;

class MyQueue {
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

TEST(leetcode1, case1) {
  MyQueue s;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expect = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expect);
}